#!/usr/bin/env python
# make a horizontal bar chart

from pylab import *

# XXX fill me
val = [5214, 4970, 875, 874, 650]
pos = [0.15, 0.25, 0.35, 0.45, 0.55]

figure(1, figsize=(7,4))
barh(pos,val, align='center', height=0.04, color="#4f81bd", linewidth=0)
tick_params(pad=10)
yticks(pos, ('2 x Xeon E5420 8 cores', 'AMD FX-8120 8 cores',
'AMD X2 720 1 core', 'AMD FX-8120 1 core', 'Xeon E5420 1 core'))
xlabel('\nc/s (more is better)')
title('GNOME Keyring Cracking Benchmarks\n')
grid(axis='x')
tight_layout()
savefig("Keyring Benchmarks.png")
show()
