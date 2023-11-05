import tkinter as tk
from tkinter import filedialog
from PIL import Image, ImageTk

def rgb_to_rgb565(r, g, b):
    # 将RGB值转换为RGB565格式
    r = (r >> 3) & 0x1F
    g = (g >> 2) & 0x3F
    b = (b >> 3) & 0x1F
    return (r << 11) | (g << 5) | b

def image_to_rgb565(image):
    try:
        # 转换图像为RGB模式
        img = image.convert("RGB")
        
        # 获取图像的宽度和高度
        width, height = img.size
        
        # 创建一个存储RGB565数据的列表
        rgb565_data = []
        
        # 遍历图像的每个像素，并转换为RGB565格式
        for y in range(height):
            for x in range(width):
                r, g, b = img.getpixel((x, y))
                rgb565_value = rgb_to_rgb565(r, g, b)
                rgb565_data.append(rgb565_value)
                
        return rgb565_data, width, height
        
    except Exception as e:
        print("Error:", e)
        return None

def open_image():
    file_path = filedialog.askopenfilename(filetypes=[("JPEG Files", "*.jpg")])
    if file_path:
        global img, img_width, img_height, img_tk
        img = Image.open(file_path)
        img_width, img_height = img.size
        img_tk = ImageTk.PhotoImage(img)
        image_label.config(image=img_tk)
        export_button.config(state=tk.NORMAL)

def export_image():
    if img:
        export_path = filedialog.asksaveasfilename(defaultextension=".h")
        if export_path:
            name = name_var.get()
            rgb565_data, width, height = image_to_rgb565(img)
            if rgb565_data:
                try:
                    with open(export_path, 'w') as f:
                        # 写入.h文件的头部信息
                        
                        f.write("#define IMAGE_DATA_H\n\n")
                        f.write(f"const uint16_t {name}[0x4000] PROGMEM = {{\n")

                        # 写入RGB565数据
                        for i, value in enumerate(rgb565_data):
                            f.write("0x{:04X}".format(value))
                            if i < len(rgb565_data) - 1:
                                f.write(", ")
                            if (i + 1) % width == 0:
                                f.write("\n")

                        # 写入.h文件的尾部信息
                        f.write("};\n\n")
                    

                    export_label.config(text="Image exported to " + export_path)
                except Exception as e:
                    export_label.config(text="Error: " + str(e))
            else:
                export_label.config(text="Error converting image to RGB565!")

# 创建GUI窗口
window = tk.Tk()
window.title("单张图片转565转换器by伊娃")
window.geometry("400x450")

# 创建用于显示图像的标签
image_label = tk.Label(window)
image_label.pack()

# 创建输入文字的标签和输入框
name_label = tk.Label(window, text="变量名称:")
name_label.pack()
name_var = tk.StringVar()
name_entry = tk.Entry(window, textvariable=name_var)
name_entry.pack()

# 创建打开按钮
open_button = tk.Button(window, text="打开单张图片", command=open_image)
open_button.pack()

# 创建导出按钮
export_button = tk.Button(window, text="导出h文件", command=export_image, state=tk.DISABLED)
export_button.pack()

# 创建用于显示导出状态的标签
export_label = tk.Label(window, text="")
export_label.pack()

export_label = tk.Label(window, text="B站关注：伊娃老师来了")
export_label.pack()

export_label = tk.Label(window, text="使用说明：")
export_label.pack()

export_label = tk.Label(window, text="1.输入变量名称,跟Arduino对应的")
export_label.pack()

export_label = tk.Label(window, text="2.点击打开单张图片")
export_label.pack()

export_label = tk.Label(window, text="3.点击导出h文件")
export_label.pack()

export_label = tk.Label(window, text="比如变量是img，Arduino就要输入tft.pushImage(0,0,128,128,img)")
export_label.pack()

img = None
img_width, img_height = 0, 0
img_tk = None

window.mainloop()
