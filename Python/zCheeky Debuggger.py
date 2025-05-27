from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import re
import time

username = "blunderrasta"
mode = "rapid"
url = f"https://www.chess.com/member/{username}/stats/{mode}"

options = Options()
options.add_argument("--headless") 
options.add_argument("--disable-gpu")
options.add_argument("--no-sandbox")
driver = webdriver.Chrome(options=options)
driver.get(url)

time.sleep(3)  

soup = BeautifulSoup(driver.page_source, "html.parser")
driver.quit()

percentile = None
rank = None

for block in soup.find_all("div", class_="icon-block-small-content"):
    text = block.get_text(strip=True)

    # Match decimal or whole number percentiles like 97.9% or 98%
    if not percentile:
        match = re.search(r"\d{1,3}(\.\d+)?%", text)
        if match:
            percentile = match.group()

    # Match ranks like #123456
    if not rank:
        match = re.search(r"#\d{5,}", text)
        if match:
            rank = match.group()

print(f"Mode: {mode}")
print("Percentile:", percentile if percentile else "Not found")
print("Rank:", rank if rank else "Not found")