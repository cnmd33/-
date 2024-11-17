"""
使用 XOR Cipher ，编写一个 Python 程序encrypted.py，实现对文件的加密。程序需要读取一个文本文件input.txt，对其内容进行加密，
并将加密后的内容写入另一个文件encrypted.txt。加密的密钥为你的学号。
 **功能**：
   - 使用 XOR Cipher 对文件内容进行加密和解密。
   - 不许使用任何库（即不许使用import）！！！否则此题零分。
   我的学号为20246787
"""

def xor_cipher(data, key):
    return ''.join(chr(ord(c) ^ key) for c in data)

def encrypt(data, key):
    return xor_cipher(data, key)

def decrypt(data, key):
    return xor_cipher(data, key)

def main():
    key = 20246787
    with open('input.txt', 'r') as f:
        data = f.read()
    encrypted_data = encrypt(data, key)
    with open('encrypted.txt', 'w') as f:
        f.write(encrypted_data)

