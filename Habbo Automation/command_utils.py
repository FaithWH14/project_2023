from typing import Optional, Tuple
from subprocess import Popen, PIPE
import time

def run_cmd(
        cmd: str, usePowershell: bool = False
) -> Tuple[Optional[Exception], Tuple[str, str]]:

    if usePowershell:
        cmd = f'Powershell -Command "{cmd}"'

    p = Popen([f"{cmd}"], stdout=PIPE, stderr=PIPE)

    return None

    # try:
    #     stdout, stderr = p.stdout.readline(), p.stderr.readline()

    # except Exception as err:
    #     return err, ("", "")

    # # set to 3 seconds to execute command
    # time.sleep(1)

    # return None, (stderr, stdout)

