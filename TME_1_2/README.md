# TME 1
## 3000028 +

### Exercice 1
    Q1.1: Il y a une erreur de segmentation!


    Q1.2: A i = 0, i essaye de prendre la valeur 4294967295
    A l'occurrence d'après, la condition du for est toujours respecter car i est toujours supérieur ou égale à 0 et donc on essaye d'accéder à une vameur non allouée du tableau, donc segmentation fault


    Q1.3: Il y a deux solutions pour corriger l'erreur
    On retire >= par > ligne 12 et après la boucle on rajoute tab[i]=0
    On déclare i en int et non en unsigned int


    Q1.4: A la lecture du code, le programme ne fait qu'enregistrer une adresse mise en parametre puis l'affiche
    Erreur de segmentation

    Q1.5: Le print new->rue affiche "0x0"
    Après le break 16, l'erreur survient à la ligne 15. La cause de l'erreur : on essaye de mettre dans un espace memoire pointé par new->rue ur un emplacement non alloué, il y a donc une segmentation fault.
    Nous pouvons, afin de corriger le programme nous pouvons mettre un malloc sur new->rue : malloc(strlen(r)*sizeof(char))
    Ce qui alloue à new->rue un emplacement capable de prendre rue

    Q1.6: Il crée un tableau dans une structure de donnée prévu à cet effet, il crée un tableau de 100 places pour des int.
    Il place des int dans le tableau et affiche le tableau.
    Le programme séxécute bien, sans erreur apparante.

    Q1.7: Le programme ne libère pas le tableau avec un free(t), il libère seulement maxTaille et position.

    Q1.8: Les 400 bytes perdues correspondent au tableau perdu puisque le free(t) ne libère pas la mémoire des tab alloués dans initTableau.

    Q1.9: free(t->tab); à la ligne juste avant free(t);

### Exercice 2
    .Q2.1: Nous avons choisi la 2ème méthode pour avoir moins de mémoire allouée ( 1ère méthode copie tableau)
    
       
