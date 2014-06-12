#!/usr/bin/env python
# make a horizontal bar chart

from pylab import *

val = [125672, 62836, 2676, 2566]
pos = [0.15, 0.25, 0.35, 0.45]

figure(1, figsize=(7,4))
barh(pos,val, align='center', height=0.04, color="#4f81bd", linewidth=0)
tick_params(pad=10)
yticks(pos, ('ATI 7970 GPU + 8x OMP', 'GTX 570 GPU + 8x OMP',
    'AMD FX-8120 8 cores', '2 x Xeon E5420 8 cores'))
xlabel('\nc/s (more is better)')
title('ZIP cracking benchmarks\n')
grid(axis='x')
tight_layout()
savefig("ZIP Benchmarks.png")
show()
