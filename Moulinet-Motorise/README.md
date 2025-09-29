[ DESC ] Contrôle d'un moteur avec l'aide du MOSFET.

1. Le [ moteur ] fonctionne par induction (=> courant magnétique qui va faire tourner le rotor).
Il est alimente par un pile 9V et contrôlé par le MOSFET (=transistor).

2. Le [ MOSFET / transistor ] sert de bouton pour controler le moteur.
En fonction de la tension (5V en provenance de l'Arduino) appliquée sur la GATE, cela va permettre de laisser passer ou pas le courant.

3. La [ diode ] de roue libre sert à evacuer la tension inverse liberee par le moteur pour eviter qu'elle n'abime le circuit.