import uiautomation as auto
import pyautogui
import time

from get_image import get_img
# wnd = auto.WindowControl(Name="Habbo COM | PROPROZAI")
# wnd.Maximize()
# wnd.SetActive()

avatar_imgs = get_img("avatar")
dance_imgs = get_img("dance")

count = 0
sleep_dict = {dance_imgs[0]: 2, dance_imgs[1]: 2}
sleep_duration = 2  # initial sleeping time set to 2 seconds
while count < 100:

    time.sleep(sleep_duration)

    for img in avatar_imgs:

        xy_location = pyautogui.locateOnScreen(f"{img}", confidence=0.5)
        if xy_location is None:
            continue
        pyautogui.click(xy_location)
        print("the image is ", img)

        time.sleep(1)

        for dance in dance_imgs:
            xy_dancing = pyautogui.locateOnScreen(f"{dance}")
            if xy_dancing is None:
                continue
            print("dance image is ", dance)
            pyautogui.click(xy_dancing)
            sleep_duration = sleep_dict.get(dance)
            print("next sleeping duration is ", sleep_duration)
            break

        break

    count += 1
