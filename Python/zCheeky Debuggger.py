from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import re
import time

username = "blunderrasta"
mode = "blitz"
url = f"https://www.chess.com/member/{username}/stats/{mode}"

options = Options()
options.add_argument("--headless") 
driver = webdriver.Chrome(options=options)
driver.get(url)

time.sleep(3)  

soup = BeautifulSoup(driver.page_source, "html.parser")
driver.quit()

percentile = None
rank = None

for block in soup.find_all("div", class_="icon-block-small-content"):
    text = block.get_text(strip=True)
    if not percentile and re.search(r"\d{1,3}%$", text):
        percentile = re.search(r"\d{1,3}%$", text).group()
    if not rank and re.search(r"#\d{5,}", text):
        rank = re.search(r"#\d{5,}", text).group()

print(f"Mode: {mode}")
print("Percentile:", percentile if percentile else "Not found")
print("Rank:", rank if rank else "Not found")