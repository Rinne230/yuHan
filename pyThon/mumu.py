from win32gui import *
import win32gui
import win32api
import win32con
import time
from pygame import event
import pygame
import imagehash
from PIL import Image, ImageGrab

pygame.init()
titles = set()
hash_stone = imagehash.average_hash(Image.open('E:/python_code/little tool/srk scrpit/imgs/stone_img.jpg'), hash_size=6)#储存石头的哈希值，用于后续比较


now_pic_path = 'E:/python_code/little tool/srk scrpit/imgs/now_img.jpg'

def foo(hwnd,mouse):#两个参数，句柄，鼠标，获取窗口信息
 if IsWindow(hwnd) and IsWindowEnabled(hwnd) and IsWindowVisible(hwnd):#判断是否是窗口以及该窗口是否可用和可见
  titles.add(GetWindowText(hwnd))#先放入集合

def play_game():#判断是否是MUMU
    global titles#全局变量
    EnumWindows(foo, 0)#枚举所有窗口，并对每个窗口调用foo函数
    lt = [t for t in titles if t]#再复制到列表
    lt.sort()#列表排序

    for t in lt:#枚举列表
        print(t)
        if(t.find('MuMu模拟器')) >= 0:
            hwnd = win32gui.FindWindow(None, t)
            print(hwnd)
            win32gui.SetWindowPos(hwnd, win32con.HWND_TOPMOST,0,0,620, 360,win32con.SWP_SHOWWINDOW)#将hwnd置于最顶层（HWND_TOPMOST），并设置其左上角坐标为(0,0)，宽度为620，高度为360
            hwnd=win32gui.FindWindow(None, t)#第一个参数是窗口类名或者是窗口标题，第二个参数是父窗口的句柄
            print(hwnd)
            size = win32gui.GetWindowRect(hwnd)#获取窗口大小
            print(size)
            return size

def is_using_stone(topx, topy):
    ImageGrab.grab((topx + 680, topy + 250, topx + 850, topy + 400)).save(now_pic_path)#截取屏幕上指定区域的图像
    hash_now = imagehash.average_hash(Image.open(now_pic_path), hash_size=6)#计算该图像的哈希值
    hash_diff = 1 - (hash_now - hash_stone) / len(hash_now.hash) ** 2#与预先计算好的石头图像的哈希值进行比较，计算出两者之间的相似度
    print(hash_diff)
    if(hash_diff >= 0.9):
        return True
    else:
        return False

def game():
    size = play_game()
    topx, topy = size[0], size[1]

    while True:
        win32api.SetCursorPos([size[0] + 550, size[1] + 300])
        if is_using_stone(topx, topy):
            break
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_LEFTDOWN, 0, 0)
        time.sleep(1)
        win32api.SetCursorPos([size[0] + 550, size[1] + 300])
        if is_using_stone(topx, topy):
            break
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_LEFTDOWN, 0, 0)
        time.sleep(1)
        win32api.SetCursorPos([size[0] + 495, size[1] + 260])
        if is_using_stone(topx, topy):
            break
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_LEFTDOWN, 0, 0)
        time.sleep(1)
        win32api.SetCursorPos([size[0] + 495, size[1] + 260])
        if is_using_stone(topx, topy):
            break
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_LEFTDOWN, 0, 0)
        time.sleep(1)
        win32api.SetCursorPos([size[0] + 570, size[1] + 300])
        if is_using_stone(topx, topy):
            break
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_LEFTDOWN, 0, 0)
        time.sleep(1)
if __name__ == '__main__':
    game()
