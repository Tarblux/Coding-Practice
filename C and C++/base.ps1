function Test-WinUtilPackageManager {
    <#

    .SYNOPSIS
        Checks if Winget and/or Choco are installed

    .PARAMETER winget
        Check if Winget is installed

    .PARAMETER choco
        Check if Chocolatey is installed

    #>

    Param(
        [System.Management.Automation.SwitchParameter]$winget,
        [System.Management.Automation.SwitchParameter]$choco
    )

    $status = "not-installed"

    if ($winget) {
        # Check if Winget is available while getting it's Version if it's available
        $wingetExists = $true
        try {
            $wingetVersionFull = winget --version
        } catch [System.Management.Automation.CommandNotFoundException], [System.Management.Automation.ApplicationFailedException] {
            Write-Warning "Winget was not found due to un-availablity reasons"
            $wingetExists = $false
        } catch {
            Write-Warning "Winget was not found due to un-known reasons, The Stack Trace is:`n$($psitem.Exception.StackTrace)"
            $wingetExists = $false
	}

        # If Winget is available, Parse it's Version and give proper information to Terminal Output.
	# If it isn't available, the return of this funtion will be "not-installed", indicating that
        # Winget isn't installed/available on The System.
	if ($wingetExists) {
            # Check if Preview Version
            if ($wingetVersionFull.Contains("-preview")) {
                $wingetVersion = $wingetVersionFull.Trim("-preview")
                $wingetPreview = $true
            } else {
                $wingetVersion = $wingetVersionFull
                $wingetPreview = $false
            }

            # Check if Winget's Version is too old.
            $wingetCurrentVersion = [System.Version]::Parse($wingetVersion.Trim('v'))
            # Grabs the latest release of Winget from the Github API for version check process.
            $response = Invoke-RestMethod -Uri "https://api.github.com/repos/microsoft/Winget-cli/releases/latest" -Method Get -ErrorAction Stop
            $wingetLatestVersion = [System.Version]::Parse(($response.tag_name).Trim('v')) #Stores version number of latest release.
            $wingetOutdated = $wingetCurrentVersion -lt $wingetLatestVersion
            Write-Host "===========================================" -ForegroundColor Green
            Write-Host "---        Winget is installed          ---" -ForegroundColor Green
            Write-Host "===========================================" -ForegroundColor Green
            Write-Host "Version: $wingetVersionFull" -ForegroundColor White

            if (!$wingetPreview) {
                Write-Host "    - Winget is a release version." -ForegroundColor Green
            } else {
                Write-Host "    - Winget is a preview version. Unexpected problems may occur." -ForegroundColor Yellow
            }

            if (!$wingetOutdated) {
                Write-Host "    - Winget is Up to Date" -ForegroundColor Green
                $status = "installed"
            }
            else {
                Write-Host "    - Winget is Out of Date" -ForegroundColor Red
                $status = "outdated"
            }
        } else {
            Write-Host "===========================================" -ForegroundColor Red
            Write-Host "---      Winget is not installed        ---" -ForegroundColor Red
            Write-Host "===========================================" -ForegroundColor Red
            $status = "not-installed"
        }
    }

    if ($choco) {
        if ((Get-Command -Name choco -ErrorAction Ignore) -and ($chocoVersion = (Get-Item "$env:ChocolateyInstall\choco.exe" -ErrorAction Ignore).VersionInfo.ProductVersion)) {
            Write-Host "===========================================" -ForegroundColor Green
            Write-Host "---      Chocolatey is installed        ---" -ForegroundColor Green
            Write-Host "===========================================" -ForegroundColor Green
            Write-Host "Version: v$chocoVersion" -ForegroundColor White
            $status = "installed"
        } else {
            Write-Host "===========================================" -ForegroundColor Red
            Write-Host "---    Chocolatey is not installed      ---" -ForegroundColor Red
            Write-Host "===========================================" -ForegroundColor Red
            $status = "not-installed"
        }
    }

    return $status
}

function Get-WinUtilWingetPrerequisites {
    <#
    .SYNOPSIS
        Downloads the Winget Prereqs.
    .DESCRIPTION
        Downloads Prereqs for Winget. Version numbers are coded as variables and can be updated as uncommonly as Microsoft updates the prereqs.
    #>

    # I don't know of a way to detect the prereqs automatically, so if someone has a better way of defining these, that would be great.
    # Microsoft.VCLibs version rarely changes, but for future compatibility I made it a variable.
    $versionVCLibs = "14.00"
    $fileVCLibs = "https://aka.ms/Microsoft.VCLibs.x64.${versionVCLibs}.Desktop.appx"
    # Write-Host "$fileVCLibs"
    # Microsoft.UI.Xaml version changed recently, so I made the version numbers variables.
    $versionUIXamlMinor = "2.8"
    $versionUIXamlPatch = "2.8.6"
    $fileUIXaml = "https://github.com/microsoft/microsoft-ui-xaml/releases/download/v${versionUIXamlPatch}/Microsoft.UI.Xaml.${versionUIXamlMinor}.x64.appx"
    # Write-Host "$fileUIXaml"

    Try{
        Write-Host "Downloading Microsoft.VCLibs Dependency..."
        Invoke-WebRequest -Uri $fileVCLibs -OutFile $ENV:TEMP\Microsoft.VCLibs.x64.Desktop.appx
        Write-Host "Downloading Microsoft.UI.Xaml Dependency...`n"
        Invoke-WebRequest -Uri $fileUIXaml -OutFile $ENV:TEMP\Microsoft.UI.Xaml.x64.appx
    }
    Catch{
        throw [WingetFailedInstall]::new('Failed to install prerequsites')
    }
}

function Get-WinUtilWingetLatest {
    <#
    .SYNOPSIS
        Uses GitHub API to check for the latest release of Winget.
    .DESCRIPTION
        This function grabs the latest version of Winget and returns the download path to Install-WinUtilWinget for installation.
    #>
    # Invoke-WebRequest is notoriously slow when the byte progress is displayed. The following lines disable the progress bar and reset them at the end of the function
    $PreviousProgressPreference = $ProgressPreference
    $ProgressPreference = "silentlyContinue"
    Try{
        # Grabs the latest release of Winget from the Github API for the install process.
        $response = Invoke-RestMethod -Uri "https://api.github.com/repos/microsoft/Winget-cli/releases/latest" -Method Get -ErrorAction Stop
        $latestVersion = $response.tag_name #Stores version number of latest release.
        $licenseWingetUrl = $response.assets.browser_download_url | Where-Object {$_ -like "*License1.xml"} #Index value for License file.
        Write-Host "Latest Version:`t$($latestVersion)`n"
        Write-Host "Downloading..."
        $assetUrl = $response.assets.browser_download_url | Where-Object {$_ -like "*Microsoft.DesktopAppInstaller_8wekyb3d8bbwe.msixbundle"}
        Invoke-WebRequest -Uri $licenseWingetUrl -OutFile $ENV:TEMP\License1.xml
        # The only pain is that the msixbundle for winget-cli is 246MB. In some situations this can take a bit, with slower connections.
        Invoke-WebRequest -Uri $assetUrl -OutFile $ENV:TEMP\Microsoft.DesktopAppInstaller.msixbundle
    }
    Catch{
        throw [WingetFailedInstall]::new('Failed to get latest Winget release and license')
    }
    $ProgressPreference = $PreviousProgressPreference
}

function Install-WinUtilWinget {
    <#

    .SYNOPSIS
        Installs Winget if it is not already installed.

    .DESCRIPTION
        This function will download the latest version of Winget and install it. If Winget is already installed, it will do nothing.
    #>
    $isWingetInstalled = Test-WinUtilPackageManager -winget

    Try {
        if ($isWingetInstalled -eq "installed") {
            Write-Host "`nWinget is already installed.`r" -ForegroundColor Green
            return
        } elseif ($isWingetInstalled -eq "outdated") {
            Write-Host "`nWinget is Outdated. Continuing with install.`r" -ForegroundColor Yellow
        } else {
            Write-Host "`nWinget is not Installed. Continuing with install.`r" -ForegroundColor Red
        }

        # Gets the computer's information
        if ($null -eq $sync.ComputerInfo){
            $ComputerInfo = Get-ComputerInfo -ErrorAction Stop
        } else {
            $ComputerInfo = $sync.ComputerInfo
        }

        if (($ComputerInfo.WindowsVersion) -lt "1809") {
            # Checks if Windows Version is too old for Winget
            Write-Host "Winget is not supported on this version of Windows (Pre-1809)" -ForegroundColor Red
            return
        }

        # Install Winget via GitHub method.
        # Used part of my own script with some modification: ruxunderscore/windows-initialization
        Write-Host "Downloading Winget Prerequsites`n"
        Get-WinUtilWingetPrerequisites
        Write-Host "Downloading Winget and License File`r"
        Get-WinUtilWingetLatest
        Write-Host "Installing Winget w/ Prerequsites`r"
        Add-AppxProvisionedPackage -Online -PackagePath $ENV:TEMP\Microsoft.DesktopAppInstaller.msixbundle -DependencyPackagePath $ENV:TEMP\Microsoft.VCLibs.x64.Desktop.appx, $ENV:TEMP\Microsoft.UI.Xaml.x64.appx -LicensePath $ENV:TEMP\License1.xml
		Write-Host "Manually adding Winget Sources, from Winget CDN."
		Add-AppxPackage -Path https://cdn.winget.microsoft.com/cache/source.msix #Seems some installs of Winget don't add the repo source, this should makes sure that it's installed every time.
        Write-Host "Winget Installed" -ForegroundColor Green
        Write-Host "Enabling NuGet and Module..."
        Install-PackageProvider -Name NuGet -Force
        Install-Module -Name Microsoft.WinGet.Client -Force
        # Winget only needs a refresh of the environment variables to be used.
        Write-Output "Refreshing Environment Variables...`n"
        $ENV:PATH = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User")
    } Catch {
        Write-Host "Failure detected while installing via GitHub method. Continuing with Chocolatey method as fallback." -ForegroundColor Red
        # In case install fails via GitHub method.
        Try {
        # Install Choco if not already present
        Install-WinUtilChoco
        Start-Process -Verb runas -FilePath powershell.exe -ArgumentList "choco install winget-cli"
        Write-Host "Winget Installed" -ForegroundColor Green
        Write-Output "Refreshing Environment Variables...`n"
        $ENV:PATH = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User")
        } Catch {
            throw [WingetFailedInstall]::new('Failed to install!')
        }
    }
}

$isAdmin = [System.Security.Principal.WindowsPrincipal]::new(
    [System.Security.Principal.WindowsIdentity]::GetCurrent()).
        IsInRole('Administrators')

if(-not $isAdmin) {
  $params = @{
      FilePath     = 'powershell' # or pwsh if Core
      Verb         = 'RunAs'
      ArgumentList = @(
          '-ExecutionPolicy ByPass'
          '-File "{0}"' -f $PSCommandPath
      )
  }

  Write-Warning "About to install winget"
  Read-Host -Prompt "Press any key to continue, or CTRL-C to abort" | Out-Null


  Start-Process -Wait @params
  Write-Host "Admin stuff done..."
} else {
  Write-Host "In Admin stuff..."
  Install-WinUtilWinget
  return
}

$installs=@(
  'chocolatey',
  'Git.Git',
  'Genivia.ugrep',
  'Microsoft.WindowsTerminal',
  'AntibodySoftware.WizFile',
  'Kitware.CMake',
  'Microsoft.VCRedist.2015+.x64',
  'Microsoft.VCRedist.2015+.x64'
)

$choco_installs=@('geany','geany-plugins','winlibs')

Write-Warning "About to install the following software:"
Write-Warning "-----------------------------------------"
foreach($pkg in $installs) { Write-Host $pkg }
foreach($pkg in $choco_installs) { Write-Host $pkg }
Write-Warning "-----------------------------------------"
Write-Warning "This will use winget and chocolatey to do the installs."
Read-Host -Prompt "Press any key to continue, or CTRL-C to abort" | Out-Null


foreach($pkg in $installs) {
  Start-Process -NoNewWindow -Wait winget -ArgumentList 'install',$pkg
}

Start-Process -Verb RunAs -Wait powershell -argumentlist 'C:\ProgramData\chocolatey\bin\choco.exe','install','geany','geany-plugins','winlibs'

Write-Warning "!!! CLOSE THIS POWERSHELL AND START A NEW ONE TO UPDATE PATH!"
