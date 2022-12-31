import random
import string

def generate_code(length):
  # Generate a string of random letters, digits, and hyphens
  code = ''.join(random.choices(string.ascii_letters + '-', k=length))
  return code

# Generate a code with 8 characters
code = generate_code(8)
print(code)