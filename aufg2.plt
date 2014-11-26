set terminal pngcairo
set output "golden.png"
set logscale y 
plot "./golden.dat" u 1:2 w l , '' u 1:3 w l

