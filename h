:root{
 --bg:#fff;--text-1:#0f172a;--text-2:#5b6b7d;--border:rgba(15,23,42,.08);--primary:#3b82f6
}
*{box-sizing:border-box;margin:0;padding:0}
body{font-family:'Inter',system-ui,-apple-system,Segoe UI,Roboto,Arial,sans-serif;background:var(--bg);color:var(--text-1);line-height:1.6}
.page{max-width:1100px;margin:auto;padding:40px 20px}
.title{font-size:2rem;font-weight:800;margin-bottom:24px}
.cards-grid{display:grid;grid-template-columns:repeat(auto-fit,minmax(280px,1fr));gap:20px}
.scene{perspective:1200px}
.card{position:relative;width:100%;height:390px;border:1px solid var(--border);border-radius:16px;transform-style:preserve-3d;transition:transform .8s cubic-bezier(.2,.9,.3,1);box-shadow:0 8px 24px rgba(15,23,42,.06);overflow:hidden;background-size:cover;background-repeat:no-repeat}
.scene:hover .card,.scene:focus-within .card{transform:rotateY(180deg)}
.card__face{position:absolute;inset:0;backface-visibility:hidden;padding:20px;display:flex;flex-direction:column;justify-content:center;align-items:center}
.card__face--back{transform:rotateY(180deg)}
.card-title{font-size:1.125rem;font-weight:700}
.card-text{color:var(--text-2)}

/* ---- Tourbillon collectif au chargement ---- */
.cards-grid {
  opacity: 0;
  transform: scale(0.3) rotate(-180deg);
  animation: collectiveSwirl 1.2s cubic-bezier(.25,.9,.25,1) forwards;
  transform-origin: center center;
}

/* Animation du tourbillon collectif */
@keyframes collectiveSwirl {
  0% {
    opacity: 0;
    transform: scale(0.3) rotate(-360deg) translateY(-200px);
  }
  60% {
    opacity: 1;
    transform: scale(1.05) rotate(20deg) translateY(20px);
  }
  100% {
    opacity: 1;
    transform: scale(1) rotate(0deg) translateY(0);
  }
}

/* Chaque carte fait un micro-zoom + rebond après le tourbillon */
.card {
  animation: popIn 0.6s ease-out both;
  animation-delay: 1.2s;
}

@keyframes popIn {
  0% { transform: scale(0.8) translateY(20px); opacity: 0; }
  70% { transform: scale(1.05); opacity: 1; }
  100% { transform: scale(1); }
}


/* ---- Mise en disposition carousel type 3 cartes (style screenshot) ---- */
.carousel-container {
  display: flex;
  justify-content: center;
  align-items: center;
  gap: 1rem;
  width: 100%;
  margin-top: 2rem;
  perspective: 1200px;
}

.carousel-card {
  width: 220px;
  height: 300px;
  border-radius: 20px;
  background: linear-gradient(135deg, #6e00ff, #ff00a6);
  display: flex;
  justify-content: center;
  align-items: center;
  font-size: 1.5rem;
  font-weight: bold;
  color: white;
  transition: transform 0.6s ease, opacity 0.6s;
  position: relative;
  cursor: pointer;
}

/* Carte centrale en avant */
.carousel-card.center {
  transform: scale(1.2);
  z-index: 3;
}

/* Carte gauche */
.carousel-card.left {
  transform: translateX(-60px) scale(0.9) rotateY(20deg);
  opacity: 0.7;
  z-index: 2;
}

/* Carte droite */
.carousel-card.right {
  transform: translateX(60px) scale(0.9) rotateY(-20deg);
  opacity: 0.7;
  z-index: 2;
}

/* Animation: changement automatique toutes les 3 secondes */
@keyframes rotateCarousel {
  0% { }
  33% { }
  34% { }
  66% { }
  67% { }
  100% { }
}
/* Carrousel container */
.carousel {
  width: 300px;
  height: 300px;
  margin: 80px auto;
  position: relative;
  transform-style: preserve-3d;
  animation: rotateCarousel 10s linear infinite;
}

/* Elements (tes cartes) */
.carousel__item {
  width: 180px;
  height: 240px;
  background: linear-gradient(135deg, #7b2ff7, #f107a3);
  border-radius: 18px;
  position: absolute;
  top: 30px;
  left: 60px;
  display: flex;
  align-items: center;
  justify-content: center;
  font-size: 1.3rem;
  font-weight: 700;
  color: white;
  transform-style: preserve-3d;
}

/* Positionnement des 6 cartes en cercle */
.carousel__item:nth-child(1) { transform: rotateY(0deg) translateZ(260px); }
.carousel__item:nth-child(2) { transform: rotateY(60deg) translateZ(260px); }
.carousel__item:nth-child(3) { transform: rotateY(120deg) translateZ(260px); }
.carousel__item:nth-child(4) { transform: rotateY(180deg) translateZ(260px); }
.carousel__item:nth-child(5) { transform: rotateY(240deg) translateZ(260px); }
.carousel__item:nth-child(6) { transform: rotateY(300deg) translateZ(260px); }

/* Rotation automatique */
@keyframes rotateCarousel {
  from { transform: rotateY(0deg); }
  to   { transform: rotateY(360deg); }
}
<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Cartes</title>
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;500;700&display=swap" rel="stylesheet">
<style>
/* === Carousel amélioré : cartes agrandies + rotation 3s + arrêt carte aléatoire === */
body {
  font-family: 'Inter', sans-serif;
  background: #fff;
  margin: 0;
  padding: 0;
  display: flex;
  justify-content: center;
}

.page { max-width: 1100px; margin: auto; padding: 40px 20px; }
.title { font-size: 2rem; font-weight: 800; margin-bottom: 24px; text-align:center; }

.carousel {
  width: 500px;
  height: 500px;
  margin: 80px auto;
  position: relative;
  transform-style: preserve-3d;
  animation: spinOnce 3s ease-out forwards;
}

@keyframes spinOnce {
  from { transform: rotateY(0deg); }
  to   { transform: rotateY(360deg); }
}

.carousel__item {
  width: 300px;
  height: 380px;
  border-radius: 26px;
  background: linear-gradient(135deg, #7b2ff7, #f107a3);
  position: absolute;
  top: 60px;
  left: 100px;
  display: flex;
  align-items: center;
  justify-content: center;
  font-size: 1.8rem;
  font-weight: 700;
  color: white;
  transform-style: preserve-3d;
  transition: transform 1s ease-out;
  z-index: 1;
}

.carousel__item:nth-child(1) { transform: rotateY(0deg) translateZ(350px); }
.carousel__item:nth-child(2) { transform: rotateY(60deg) translateZ(350px); }
.carousel__item:nth-child(3) { transform: rotateY(120deg) translateZ(350px); }
.carousel__item:nth-child(4) { transform: rotateY(180deg) translateZ(350px); }
.carousel__item:nth-child(5) { transform: rotateY(240deg) translateZ(350px); }
.carousel__item:nth-child(6) { transform: rotateY(300deg) translateZ(350px); }

/* Carte mise en avant */
.carousel__item.focused {
  transform: translateZ(600px) scale(1.35) !important;
  z-index: 10;
}
  /* Zoom + éclairage 3D sur la carte mise en avant */
  .carousel__item.highlighted {
    transform: translateZ(150px) scale(1.3) rotateY(0deg) !important;
    box-shadow: 0 30px 60px rgba(255, 255, 255, 0.5),
                0 10px 25px rgba(0, 0, 0, 0.4);
    filter: brightness(1.3);
    animation: lightSweep 2s ease infinite;
  }

  /* Animation d’éclairage dynamique */
  @keyframes lightSweep {
    0% { box-shadow: 0 0 20px rgba(255,255,255,0.2); }
    50% { box-shadow: 0 0 60px rgba(255,255,255,0.6); }
    100% { box-shadow: 0 0 20px rgba(255,255,255,0.2); }
  }

</style>
</head>
<body>
  <main class="page">
    <h1 class="title">Cartes</h1>

    <section class="cards-grid" aria-label="Liste de cartes">
      <div class="carousel">
        <div class="carousel__item">Communication</div>
        <div class="carousel__item">Coopération</div>
        <div class="carousel__item">Créativité</div>
        <div class="carousel__item">Assertivité</div>
        <div class="carousel__item">Gestion du stress</div>
        <div class="carousel__item">Écoute active</div>
      </div>
    </section>
  </main>

<script>
window.addEventListener('load', () => {
  const cards = document.querySelectorAll('.carousel__item');
  const carousel = document.querySelector('.carousel');

  const randomIndex = Math.floor(Math.random() * cards.length);
  const chosen = cards[randomIndex];

  setTimeout(() => {
    chosen.classList.add('focused');
    carousel.style.animation = 'none';
  }, 3000);
});
</script>
</body>
</html>
 gere le responsive de projet pour toues les tailles d'écran en conservant l'annimation mais en redimensionne les carte