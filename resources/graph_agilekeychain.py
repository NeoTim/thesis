#!/usr/bin/env python
# make a horizontal bar chart

from pylab import *

# XXX fill me
val = [190464, 108850, 9941, 7953]
pos = [0.15, 0.25, 0.35, 0.45]

figure(1, figsize=(7,4))
barh(pos,val, align='center', height=0.04, color="#4f81bd", linewidth=0)
tick_params(pad=10)
yticks(pos, ('ATI 7970 GPU + 8x OMP', 'NVIDIA GTX 570', \
    '2 x Xeon E5420 8 cores', 'AMD FX-8120 8 cores'))
xlabel('\nc/s (more is better)')
title('Agile Keychain cracking benchmarks\n')
grid(axis='x')
tight_layout()
savefig("Agile Keychain Benchmarks.png")
show()
