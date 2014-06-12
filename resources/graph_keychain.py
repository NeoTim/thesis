#!/usr/bin/env python
# make a horizontal bar chart

from pylab import *

# XXX fill me
val = [214809, 131657, 4015, 3900]
pos = [0.15, 0.25, 0.35, 0.45]

figure(1, figsize=(7,4))
barh(pos,val, align='center', height=0.04, color="#4f81bd", linewidth=0)
tick_params(pad=10)
yticks(pos, ('ATI 7970 GPU + 8x OMP', 'ATI 7970 GPU + 1 core', \
    'AMD FX-8120 8 cores', '2 x Xeon E5420 8 cores'))
xlabel('\nc/s (more is better)')
title('Apple Keychain Cracking Benchmarks\n')
grid(axis='x')
tight_layout()
savefig("Keychain Benchmarks.png")
show()
