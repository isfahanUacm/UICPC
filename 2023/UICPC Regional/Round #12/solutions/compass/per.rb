# I have no idea what I'm doing.

nums = STDIN.read.split().map(&:to_i)
n1 = nums[0]
n2 = nums[1]
n2 -= n1
if n2 > 180
  n2 -= 360
end
if n2 <= -180
  n2 += 360
end
puts n2
