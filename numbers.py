A = '101101'
B = '110011'

numA = int(A, 2)
numB = int(B, 2)

and_result = numA & numB

sum_result = numA + numB

and_result_bin = bin(and_result)[2:]
sum_result_bin = bin(sum_result)[2:]

print(f"Побитовая операция AND для A и B: {and_result_bin}")
print(f"Сумма A и B в двоичной системе: {sum_result_bin}")
