Projeye başlangıcınızda önerdiğim yol şudur;

1. Öncelikle minilibx'i **araştırMAyın**! İlk yapmanız gereken main'den başlayarak argüman isminin .ber ile bittiğinin kontrolünü yapmalısınız.
Eğer programa yollayacağınız arguman ismi .ber ile bitmiyorsa ekrana Error yazısı bastırıp exit fonksiyonu ile çıkmalısınız.
(Argümanları bilmiyorsanız öğreniniz, sadece 5 dakika sürer.)

2. İkinci olarak haritanızı(yani map.ber dosyanızı) **get_next_line** fonksiyonu ile okutup get_next_line'dan dönen satırı bir char pointer 
dizisine eşitlemelisiniz. Unutmayın get_next_line'dan dönen satırları bir pointer'a kaydettikten sonra o dönen satırı free etmelisiniz, eğer
bunu unutursanız projenizde leak hatanız olur.

3. Haritanızı içine yazdığınız bu char pointer dizisini daha önce libft'de öğrendiğiniz **ft_split** fonksiyonuna gönderip '\n' karakteri ile 
ayırarak çift pointerlı yeni bir char dizisine eşitlemelisiniz.

4. ft_splitten dönen bu çift pointerlı diziniz '\n' yani boşluk karakterine göre bölündüğü için artık elinizde tüm haritanın satırları 
ayrı ayrı pointerlara atanmış oldu. Bu pointerların hepsini tutan da bir çift pointerınız oldu ft_split sayesinde. (Peki bunu neden yaptık. 
Bunu yapmamızın sebebi ilerleyen kısımlarda haritanızın üzerinde daha kolay ilerleyebileceksiniz. Çünkü çift pointer kullandığınız için 
haritanızın satırları üzerinde 2 boyutlu geçiş yapabileceksiniz. Örneğin 2. satırın 4. sütunu (dizi[1][3]) diyerek oradaki karaktere 
kolaylıkla ulaşabileceksiniz.

5. Şimdi ise haritanızın kontrollerini yapmanız gerek. PDF sayfasında sizden istediği haritanızın(çift pointerlı dizinizin) içinde 
sadece 1,0,E,C,P olmalıdır. Bunun kontrol fonksiyonunu yazınız. Kontrol fonksiyonunuz şunu yapmalıdır : Haritanızda bu karakterler dışında 
bir karakter varsa ekrana error yazısını bastırıp daha önce mallocla yer ayırarak oluşturduğunuz tüm alanları free etmeli ve ardından exit 
fonksiyonu ile çıkmalısınız. Free ettiğinizde leak hatanız olmaz.

6. Üstteki adımdaki gibi bu sefer haritanızda sadece 1 adet P(Player) olduğunun kontrol fonksiyonunu, haritanızın dikdörtgen olduğunun 
kontrol fonksiyonunu, haritanızın çevresinin tamamen 1'lerden(Duvarlardan) oluştuğunun kontrol fonksiyonunu yazmalısınız.

7. Tüm bu adımlar bittikten sonra artık Minilibx fonksiyonlarını öğrenmeye geçebilirsiniz. Minilibx fonksiyonlarının ne iş yaptığını 
ecole'deki arkadaşlarınızdan öğrenebilirsiniz.
