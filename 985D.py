n, h = map(int, input().split())

if(n > h*(h + 1)/2):
	l = 1
	r = 2000000000000000000
	h0 = 2000000000000000000

	while(l <= r):
		mid = (l + r)//2
		if(mid*mid - h*(h - 1)//2 <= n) :
			h0 = mid
			l = mid + 1
		else:
			r = mid - 1

	ans = 2*h0 - h
	n = n - h0*h0 + h*(h - 1)//2
	ans = ans + (n + h0 - 1)//h0
	print(ans)

else:
	l = 1
	r = h
	ans = h
	while(l <= r):
		mid = (l + r)//2
		if(mid*(mid + 1)//2 <= n):
			ans = mid
			l = mid + 1
		else:
			r = mid - 1
	n = n - ans*(ans + 1)//2
	ans = ans + (n + ans - 1)//ans
	print(ans)