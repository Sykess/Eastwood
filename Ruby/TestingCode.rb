

phi = [0, 0]
2.upto(1000000) {|i| phi << i}
2.upto(1000000) {|n| (n..1000000).step(n).each {|i| phi[i] = phi[i] / n * (n - 1)} if phi[n] == n}
puts phi.map!.with_index { |x, i| i > 0 ? x + phi[i - 1] : x}.last







