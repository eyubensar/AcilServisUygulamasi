# Acil Servis Hasta Yönetim Sistemi

Bu proje, **C programlama dili** kullanılarak geliştirilen bir **Acil Servis Hasta Yönetim Sistemi**dir. Öncelikli kuyruk (**priority queue**) yapısını kullanarak hastaların aciliyet durumuna göre sıralanmasını ve yönetilmesini sağlar.

## 🚑 Özellikler

- **Hasta Ekleme:** Hastalar ad, yaş ve aciliyet seviyesine göre eklenir.
- **Hasta Listeleme:** Aciliyet seviyesine göre sıralanmış hasta listesi görüntülenir.
- **Hasta İşleme Alma:** En yüksek öncelikli hasta işleme alınır ve **HL7 formatında** hasta bilgisi gösterilir.
- **Reçete Yazma:** İşleme alınan hastaya rastgele reçete numarası oluşturulur.
- **Hasta Silme:** Kullanıcı tarafından belirtilen hasta sistemden silinir.
- **Toplam Hasta Sayısı:** Sistemde kayıtlı olan hasta sayısı hesaplanır.

## 🛠 Kullanılan Teknolojiler

- **C Programlama Dili**
- **Bağlı Liste (Linked List) Veri Yapısı**
- **Öncelikli Kuyruk (Priority Queue) Algoritması**
- **HL7 Formatında Hasta Kaydı**

## 💻 Kurulum ve Kullanım

1. **Depoyu Klonlayın:**
   ```sh
   git clone https://github.com/kullaniciadi/proje-adi.git
   cd proje-adi
   ```

2. **Kodları Derleyin:**
   ```sh
   gcc hasta_yonetim.c -o hasta_yonetim
   ```

3. **Programı Çalıştırın:**
   ```sh
   ./hasta_yonetim
   ```

## 📌 Kullanım Senaryosu

Program çalıştırıldığında aşağıdaki menü ile karşılaşılır:

```
1 - Hasta Ekle
2 - Hasta Listele
3 - Hasta Isleme Al
4 - Recete Yaz
5 - Hasta Sil
6 - Toplam Hasta Sayisi
7 - Cikis
```

Kullanıcı ilgili seçeneği seçerek sistem içinde hasta yönetimini gerçekleştirebilir.

## 📜 Lisans

Bu proje **MIT Lisansı** ile lisanslanmıştır. Daha fazla bilgi için [LICENSE](LICENSE) dosyasına göz atabilirsiniz.

## 🤝 Katkıda Bulunma

Katkılarınızı bekliyoruz! Lütfen **pull request** göndererek veya hata bildiriminde bulunarak projeye katkıda bulunun.

---

Bu proje, **acil servislerde hasta yönetimi süreçlerini simüle etmek** amacıyla geliştirilmiştir. 🚑

