#!/usr/bin/env python
# make a horizontal bar chart

from pylab import *

# XXX fill me
val = [873984, 852992, 203400, 154270, 131350]
pos = [0.15, 0.25, 0.35, 0.45, 0.55]

figure(1, figsize=(9,4))
barh(pos,val, align='center', height=0.04, color="#4f81bd", linewidth=0)
tick_params(pad=10)
yticks(pos, ('AMD FX-8120 8 cores', '2 x Xeon E5420 8 cores',
    'AMD FX-8120 1 core', 'AMD X7 720 1 core', 'Xeon E5420 1 core'))
xlabel('\nc/s (more is better)')
title('PuTTY key cracking benchmarks\n')
grid(axis='x')
tight_layout()
savefig("PuTTY Benchmarks.png")
show()
