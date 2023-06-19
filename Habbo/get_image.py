from pathlib import Path
from typing import Literal, List

def get_img(
        category: Literal["avatar", "dance"]
) -> List:

    if category not in ["avatar", "dance"]:
        raise Exception("The category values must be avatar or dance!")

    path = Path("")
    p = path.glob(rf"img\{category}\*")
    files = [x for x in p if x.is_file()]

    return files
