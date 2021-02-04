# TME 1
## 3000028 +

### Ex 1
    Q1.1: Il y a une erreur de segmentation!


    Q1.2: A i = 0, i essaye de prendre la valeur 
    A l'occurrence d'après, la condition du for est toujours respecter car i est toujours supérieur ou égale à 0 et donc on essaye d'accéder à une vameur non allouée du tableau, donc segmentation fault



    Q1.3: Il y a deux solutions pour corriger l'erreur
    On retire >= par > ligne 12 et après la boucle on rajoute tab[i]=0
    On déclare i en int et non en unsigned int
    
