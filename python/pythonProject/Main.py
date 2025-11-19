import time
from selenium import webdriver
driver = webdriver.Chrome() # 启动浏览器
driver.get("https://www.baidu.com") # 打开某个网址
time.sleep(10)
driver.quit() # 关闭浏览器