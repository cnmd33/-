"""
使用 XOR Cipher ，再编写一个 Python 程序decrypted.py，实现对文件的解密功能，将`neuracecar_encrypted.txt`解密，解密的密钥为123456
 **功能**：
   - 使用 XOR Cipher 对文件内容进行加密和解密。
   - 不许使用任何库（即不许使用import）！！！否则此题零分。
"""
def xor_cipher(data, key):
    return ''.join(chr(ord(c) ^ key) for c in data)

def encrypt(data, key):
    return xor_cipher(data, key)

def decrypt(data, key):
    return xor_cipher(data, key)

def main():
    key = 123456
    with open('neuracecar_encrypted.txt', 'r') as f:
        data = f.read()
    decrypted_data = decrypt(data, key)
    with open('neuracecar_decrypted.txt', 'w') as f:
        f.write(decrypted_data)