select round(sum(TIV_2016),2) as TIV_2016
from insurance i
where (select count(*) from insurance i1 where i.TIV_2015 = i1.TIV_2015)>1 and 
      (select count(*) from insurance i2 where (i.LAT, i.LON) = (i2.LAT, i2.LON))=1