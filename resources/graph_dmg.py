#!/usr/bin/env python
# make a horizontal bar chart

from pylab import *

# XXX fill me
val = [56195, 46747, 8396, 7603, 1446, 1253, 1180]
pos = [0.15, 0.25, 0.35, 0.45, 0.55, 0.65, 0.75]

figure(1, figsize=(7,4))
barh(pos,val, align='center', height=0.04, color="#4f81bd", linewidth=0)
tick_params(pad=10)
yticks(pos, ('ATI 7970 GPU + 8x OMP', 'GTX 570 GPU + 8x OMP',
    '2 x Xeon E5420 8 cores', 'AMD FX-8120 8 cores', 'AMD X3 720 1 core',
    'AMD FX-8120 1 cores', 'Xeon E5420 1 core'))
xlabel('\nc/s (more is better)')
title('DMG cracking benchmarks\n')
grid(axis='x')
tight_layout()
savefig("DMG Benchmarks.png")
show()
