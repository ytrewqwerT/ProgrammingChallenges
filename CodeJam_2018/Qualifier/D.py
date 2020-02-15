from math import pi, sin, cos, fabs, pow

T = int(input())
for test in range(1, T+1, 1):
	A = float(input())
	print(str(A))
	if (A > 1.414214):
		exit()

	lower = 0.0
	upper = pi/2
	angle = (upper + lower) / 2
	while fabs(sin(angle)+cos(angle) - A) > pow(10, -20):
		if sin(angle)+cos(angle) > A:
			upper = angle
		if sin(angle)+cos(angle) < A:
			lower = angle
		angle = (upper + lower) / 2

	print("Case #{}:".format(test))
	print("{} {} {}".format(0.5*cos(angle), 0.5*sin(angle), 0.0))
	print("{} {} {}".format(0.5*sin(angle), -0.5*cos(angle), 0.0))
	print("0 0 0.5")
