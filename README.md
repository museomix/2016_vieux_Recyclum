# Recyclum

Recyclum propose un jeu de piste dans l'une des pièces du musée de Vieux-la-Romaine, qui fait découvrir au visteur la façon dont les romains recyclaient leurs déchets. Le prototype se concentre sur la réutilisation des poteries cassées.

 1 - Le visiteur lit le panneau descriptif et s'empare d'un bout de poterie cassée.
 2 - Il trouve une poterie à laquelle il manque un bout et la complète avec le bout qu'il a dans la main. Un capteur de lumière détecte que le trou a été bouché et allume une bande LED clignotante sur une des vitrine de la salle.
 3 - Le visiteur s'approche de la vitrine et découvre des jetons taillés dans des bout de poteries (une réutilisation possible). Il peut ensuite appuyer sur un bouton-poussoir situé sur la vitrine. Les LEDs sur la vitrine se figent et une LED clignotante s'allume sur une trappe dans une table en bois.
 4 - Le visiteur ouvre la trappe. Deux carrés d'aluminium (en contact quand la trapp est fermée) ne sont plus en contact et le système détecte que la trappe est ouverte et éteint toutes les LEDs.
 5 - Une fois tout cela effectué, le visiteur est invité à refermer la trappe et remettre le bout de poterie au début du parcours.

Le matériel utlisé :
 - Un Arduino sur lequel tourne le code dans ce repository
 - Un capteur de lumière
 - Un bouton poussoir
 - Un bandeau de LED néopixel
 - Une LED classique
 - Plein de fils
