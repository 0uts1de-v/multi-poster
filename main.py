import time
import pyautogui as pyag


def post(k):
    for i in range(k):
        pyag.hotkey("ctrl","v")
        pyag.typewrite("\n")


def main():
    print("Number of bombs:", end="")

    k = int(input())

    for i in range(5):
        print(5-i)
        time.sleep(1)

    post(k)


if __name__ == "__main__":
    main()
