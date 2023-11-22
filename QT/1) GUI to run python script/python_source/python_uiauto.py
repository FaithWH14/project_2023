import uiautomation as auto
import argparse

def windowK():
    auto.SendKeys("{WIN}K")
    return

def windowD():
    auto.SendKeys("{WIN}D")
    return

def main():
    parser = argparse.ArgumentParser(description="A simple argparse example.")

    parser.add_argument("-action", required=True, choices=["k", "d"], help="hehe")

    args = parser.parse_args()
    action = args.action

    if action == "k":
        windowK()
        print("successfully open wireless panel")

    elif action == "d":
        windowD()
        print("successfully minimize all windows")

    else:
        raise Exception("No such value")


if __name__ == "__main__":
    main()
