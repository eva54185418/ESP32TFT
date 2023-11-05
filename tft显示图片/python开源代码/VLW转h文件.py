import tkinter as tk
from tkinter import filedialog

def vlw_to_hex_array(file_path):
    with open(file_path, "rb") as file:
        data = file.read()

    hex_array = [hex(byte) for byte in data]
    return hex_array

def write_hex_array_to_h_file(hex_array, output_file_path, array_name):
    with open(output_file_path, "w") as file:
        file.write("#include <pgmspace.h>\n")
        file.write("const uint8_t {}[] PROGMEM = {{\n".format(array_name))
        for idx, hex_val in enumerate(hex_array):
            file.write("    {}, ".format(hex_val))
            if (idx + 1) % 16 == 0:
                file.write("\n")
        file.write("\n};")

def select_file():
    file_path = filedialog.askopenfilename()
    if file_path:
        print("Selected file:", file_path)

        # 获取自定义字库名
        array_name = entry_name.get()
        if not array_name:
            array_name = "font_data"  # 默认字库名

        # 处理VLW文件并输出为.h文件
        hex_array = vlw_to_hex_array(file_path)

        # 弹出文件选择对话框，获取输出文件路径和名称
        output_file_path = filedialog.asksaveasfilename(defaultextension=".h", filetypes=[("Header Files", "*.h")])
        if output_file_path:
            write_hex_array_to_h_file(hex_array, output_file_path, array_name)
            print("Hex array has been written to:", output_file_path)

            # 在视窗中显示输出成功信息
            success_label.config(text="输出成功！Hex数组已写入 {}".format(output_file_path))

# 创建主窗口
root = tk.Tk()
root.title("文件选择窗口")
root.geometry("400x400")

# 创建输入框
entry_label_name = tk.Label(root, text="请输入字库名：")
entry_label_name.pack()
entry_name = tk.Entry(root)
entry_name.pack()

# 创建选择文件按钮
select_button = tk.Button(root, text="选择文件", command=select_file)
select_button.pack(pady=20)





# 创建用于显示输出成功信息的标签
success_label = tk.Label(root, text="", fg="green")
success_label.pack()

# 进入主事件循环
root.mainloop()
