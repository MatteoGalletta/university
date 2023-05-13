inv [] = []
inv (e:es) = (inv es)++[e]

inv "abc"
