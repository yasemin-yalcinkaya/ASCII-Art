# ASCII-Art

Ascii art creator

offset hesaplama 118
İlk 14 byte okunur
Bİr arraye atilir
Arrayin 10 11 12 13. elemanların aşağıdaki formüle göre hesaplanmasıyla offset değeri bulunur.
array[10]*256^0 + array[11]*256^1 + array[12]*256^2 + array[13]*256^3
Burada arrayin 10-13.değerlerinin 256lık tabanda değeri hesaplanır. Bu da bize offset değerini verir.
----
Dosya boyutu hesaplama(Byte, Diskte kapladığı alan)  374
İlk 14 byte okunur
Bİr arraye atilir
Arrayin 2 3 4 5. elemanların aşağıdaki formüle göre hesaplanmasıyla dosya boyutu bulunur.
array[2]*256^0 + array[3]*256^1 + array[4]*256^2 + array[5]*256^3
Burada arrayin 2-5.değerlerinin 256lık tabanda değeri hesaplanır. Bu da bize dosya boyunutu verir.
---
Görüntü Bilgi Başlığı
İlk 14 bayttan sonraki 40 bayt görüntü bilgi başlığıdır. (Birinci maddede belirtildiği gabi)
1-Başlık boyutu, 4 byte
2-Görüntü genişliği(piksel), 4 byte
3-Görüntü yüksekliği(piksel), 4 byte
4-Renk düzlemi sayısı, 2 byte
5-piksel başına bit sayısı(1-24), 2 byte
6-sıkıştırma, bayt(0 varsayılmıştır), 4 byte
7-Görüntü boyutu, 4 byteRenk sayısı ve önemli renkler byte sayısı, her biri 4 byte
---
Görüntünün Saklanması
1-Görüntü satır satır saklanır
2-Her piksel 3 byte gerektirir
3-Her satırın bir satır sonu işareti vardır
4-Yani dosyanın resim kısmı ((10*10=100=>size) 100*3+10*2=320'e eşittir)
5-Başlık katsayıları için 54 byte'ın eklenmesi dosya boyutunu verir 320+54=374 byte.
