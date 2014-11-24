set terminal pngcairo
set output "spektral_2d.png"
plot "./aufg4_spektral.2d" 
set output "spektral_3d.png"
splot "./aufg4_spektral.3d"
