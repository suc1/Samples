import sys

#fileName = '50G.dat'   #太浪费时间了
fileName = '4G.dat'     #2^32=4 294 967 296     #2^31=2 147 483 648     #创建文件1.3Min, 产生Hash耗时58 秒，传输文件耗时16分钟
content = ': 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n'

length = 0
line =0
f = open(fileName, "w")
#while length <= 50 * 1024 * 1024 * 1024:
while length <= 4 * 1024 * 1024 * 1024:
    if line%1000 == 0:
        #python 2
        sys.stdout.write('\r' + str(line))
        sys.stdout.flush()
        #python 3
        #print(str(line), end="\r", flush=True)
    lineStr = str(line) + content
    f.write(lineStr)
    line += 1
    length += len(lineStr)
f.close()