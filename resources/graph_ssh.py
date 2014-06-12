#!/usr/bin/env python
# make a horizontal bar chart

from pylab import *

# XXX fill me
val = [1899000, 362003, 259072, 42040]
pos = [0.15, 0.25, 0.35, 0.45]

figure(1, figsize=(7,4))
barh(pos,val, align='center', height=0.04, color="#4f81bd", linewidth=0)
tick_params(pad=10)
yticks(pos, (
    'ssh-ng @ AMD FX-8120 8 cores', 'ssh-ng @ AMD FX-8120 1 cores',
    'ssh @ AMD FX-8120 8 cores', 'ssh @ AMD FX-8120 1 cores'))
xlabel('\nc/s (more is better)')
title('SSH private key cracking benchmarks\n')
grid(axis='x')
tight_layout()
savefig("SSH Benchmarks.png")
show()
