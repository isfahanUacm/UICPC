# I have no idea what I'm doing.

nums = STDIN.read.split().map(&:to_i)
n = nums[0]
d = 0
t = 50
for i in 1..n-2
  if [nums[i], nums[i+2]].max < t
    d = i
    t = [nums[i], nums[i+2]].max
  end
end
puts d.to_s + " " + t.to_s
