from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By

driver = webdriver.Chrome(r"C:\Program Files\Google\Chrome\Application\chrome.exe")
driver.maximize_window()
driver.get("http://www.habbo.com")

cookies_btn = driver.find_element(By.XPATH, '//*[@id="onetrust-accept-btn-handler"]')
cookies_btn.click()

email_box = driver.find_element(By.XPATH, '//*[@id="habboLoginForm"]/div[1]/fieldset[1]/div/input')
email_box.send_keys("cwh.wen.hao@gmail.com")

password_box = driver.find_element(By.XPATH, '//*[@id="habboLoginForm"]/div[1]/fieldset[2]/div/input')
password_box.send_keys("testing123")

letsGo_btn = driver.find_element(By.XPATH, '//*[@id="habboLoginForm"]/div[2]/div/button')
letsGo_btn.click()