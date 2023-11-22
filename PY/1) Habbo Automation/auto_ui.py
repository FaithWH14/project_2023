import uiautomation as auto
import subprocess
import time
import pyperclip

from command_utils import run_cmd
from CONSTANT import GOOGLE_CHROME_PATH, HABBO_LAUNCHER_PATH

# Initiate New Google Chrome
run_cmd(GOOGLE_CHROME_PATH)
# if err is not None:
#     raise err

chrome_wnd = auto.PaneControl(Name="New Tab - Google Chrome")
chrome_wnd.Maximize()

searchbar = chrome_wnd.EditControl(Name="Address and search bar")
searchbar.SendKeys("www.habbo.com")
searchbar.SendKeys("{ENTER}")
try:
    email_box = chrome_wnd.EditControl(Name="Email")
    email_box.SendKeys("???")

    # skip password as it is auto-saved
    time.sleep(1)
    letsGo_btn = chrome_wnd.ButtonControl(Name="LET'S GO!")
    letsGo_btn.GetInvokePattern().Invoke()

except Exception:
    pass

time.sleep(1)

download_btn = chrome_wnd.HyperlinkControl(Name="DOWNLOAD")
download_btn.GetInvokePattern().Invoke()

# Copy LINK
copy_btn = chrome_wnd.ButtonControl(Name="COPY")
copy_btn.GetInvokePattern().Invoke()

chrome_wnd.Minimize()

# =============================================================================
# Habbo Launcher

run_cmd(HABBO_LAUNCHER_PATH)
# if err is not None:
#     raise err

habbo_launcher_wnd = auto.PaneControl(Name="Habbo")
habbo_launcher_wnd.SetFocus()
login_code_box = habbo_launcher_wnd.EditControl(
    Name="Paste the login code from the Habbo website here:")
login_code = pyperclip.paste()
login_code_box.SendKeys(login_code)

# login buffer time
time.sleep(2)

classic_btn = habbo_launcher_wnd.ButtonControl(Name="Classic")
classic_btn.GetInvokePattern().Invoke()

# =============================================================================
# Habbo

habbo_wnd = auto.WindowControl(ClassName="ApolloRuntimeContentWindow")
habbo_wnd.Maximize()
