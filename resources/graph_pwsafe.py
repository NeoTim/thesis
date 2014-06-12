#!/usr/bin/env python
# make a horizontal bar chart

from pylab import *

# XXX fill me
val = [27131, 11815, 6826, 1204]
pos = [0.15, 0.25, 0.35, 0.45]

figure(1, figsize=(7,4))
barh(pos,val, align='center', height=0.04, color="#4f81bd", linewidth=0)
tick_params(pad=10)
yticks(pos, ('GTX 570 GPU', 'ATI 6970 GPU', 'AMD FX-8120 8 cores', \
    'AMD FX-8120 1 cores'))
xlabel('\nc/s (more is better)')
title('Password Safe Cracking Benchmarks\n')
grid(axis='x')
tight_layout()
savefig("Password Safe Benchmarks.png")
show()
