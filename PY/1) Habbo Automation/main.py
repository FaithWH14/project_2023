import uiautomation as auto
import pyautogui
import time
import random

from query_time_now import query_now

count = 0

random_words = [
    ":sit", ":stand"
    # "Visit our website for more information about HIA-hiahabbo com"
]
while count < 30:
    if count % 2 == 0:
        selected_words = random_words[0]
    else:
        selected_words = random_words[1]
    waitTime = random.choice([1])
    # selected_words = random.choice(random_words)
    print("time is ", waitTime)
    print("selected words ", selected_words)
    time.sleep(waitTime)
    wnd = auto.WindowControl(Name="Habbo COM | PROPROZAI")
    wnd.Maximize()
    wnd.SetActive()

    test = pyautogui.locateOnScreen(r"img\chatbox.png")
    print("xy coordinate ", test)
    pyautogui.moveTo(test)
    pyautogui.write(selected_words)  # words to say
    # pyautogui.write(query_now())
    pyautogui.press("ENTER")

    count += 1
