import uiautomation as auto
import pyautogui
import time
import random

from get_image import get_img

def walk(
    step: int = 2, walk_times: int = 50,
    isRandom: bool = False, duration: int = 3):

    avatar_imgs = get_img("avatar")
    x, y, ori_x, ori_y = 0, 0, 0, 0
    for img in avatar_imgs:
        print("image", img)
        step_xy = pyautogui.locateOnScreen(rf"{img}", confidence=0.6)
        if step_xy is None:
            continue

        y, x = pyautogui.center(step_xy)
        print("y", y, "x", x)
        ori_y, ori_x = y, x

        break

    if x + y + ori_x + ori_y == 0:
        raise Exception("Failed to detect the avatar image!")

    final_step = step
    for i in range(walk_times):
        print("walk times", i)
        if isRandom:
            final_step = random.choice(range(1, step))
        print("final step", final_step)
        time.sleep(duration)

        if i % 10 == 0:
            y = ori_y
            x = ori_x
        elif i % 2 == 0:
            y += 30 * final_step
            x += 15 * final_step
        else:
            y -= 30 * final_step
            x -= 15 * final_step
        print("xx", x, "yy", y)

        pyautogui.click(y, x)

if __name__ == "__main__":
    walk(step=3, walk_times=1000, isRandom=True, duration=1.5)
