// Theme toggle with localStorage
(function(){
  const root = document.documentElement;
  const toggleBtn = document.getElementById('themeToggle');
  const MENU_OPEN_CLASS = 'open';
  const authOpen = document.getElementById('authOpen');
  const authModal = document.getElementById('authModal');
  const userBadge = document.getElementById('userBadge');

  const savedTheme = localStorage.getItem('theme');
  if (savedTheme === 'dark' || (!savedTheme && window.matchMedia('(prefers-color-scheme: dark)').matches)) {
    root.classList.add('dark');
    if (toggleBtn) toggleBtn.textContent = '☀️';
  }

  toggleBtn?.addEventListener('click', () => {
    const isDark = root.classList.toggle('dark');
    localStorage.setItem('theme', isDark ? 'dark' : 'light');
    toggleBtn.textContent = isDark ? '☀️' : '🌙';
  });

  // Mobile menu
  const menuToggle = document.getElementById('menuToggle');
  const navMenu = document.getElementById('navMenu');
  menuToggle?.addEventListener('click', () => navMenu?.classList.toggle(MENU_OPEN_CLASS));
  navMenu?.querySelectorAll('a').forEach(a => a.addEventListener('click', () => navMenu.classList.remove(MENU_OPEN_CLASS)));

  // Tabs
  document.querySelectorAll('.tab').forEach(tab => {
    tab.addEventListener('click', () => {
      const id = tab.getAttribute('data-tab');
      document.querySelectorAll('.tab').forEach(t => t.classList.remove('active'));
      document.querySelectorAll('.tab-panel').forEach(p => p.classList.remove('active'));
      tab.classList.add('active');
      document.getElementById(id)?.classList.add('active');
    });
  });

  // Back to top
  const backToTop = document.getElementById('backToTop');
  window.addEventListener('scroll', () => {
    if (window.scrollY > 300) backToTop?.classList.add('show'); else backToTop?.classList.remove('show');
  });
  backToTop?.addEventListener('click', () => window.scrollTo({ top:0, behavior:'smooth' }));

  // Notes widget
  const noteForm = document.getElementById('noteForm');
  const noteInput = document.getElementById('noteInput');
  const noteList = document.getElementById('noteList');

  function loadNotes(){
    try{
      return JSON.parse(localStorage.getItem('notes') || '[]');
    }catch{ return []; }
  }
  function saveNotes(notes){ localStorage.setItem('notes', JSON.stringify(notes)); }

  function renderNotes(){
    const notes = loadNotes();
    noteList.innerHTML = '';
    notes.forEach((text, idx) => {
      const li = document.createElement('li');
      li.className = 'note-item';
      const span = document.createElement('span');
      span.textContent = text;
      const btn = document.createElement('button');
      btn.className = 'btn';
      btn.textContent = 'Xóa';
      btn.addEventListener('click', () => {
        const ns = loadNotes();
        ns.splice(idx,1);
        saveNotes(ns);
        renderNotes();
      });
      li.appendChild(span); li.appendChild(btn);
      noteList.appendChild(li);
    });
  }

  noteForm?.addEventListener('submit', e => {
    e.preventDefault();
    const text = (noteInput?.value || '').trim();
    if (!text) return;
    const notes = loadNotes();
    notes.unshift(text);
    saveNotes(notes);
    noteInput.value = '';
    renderNotes();
  });

  renderNotes();

  // Contact form validation
  const contactForm = document.getElementById('contactForm');
  const errName = document.getElementById('err-name');
  const errEmail = document.getElementById('err-email');
  const errMessage = document.getElementById('err-message');
  const result = document.getElementById('contactResult');

  function isEmail(v){ return /^[\w-.]+@([\w-]+\.)+[\w-]{2,}$/i.test(v); }

  contactForm?.addEventListener('submit', e => {
    e.preventDefault();
    const name = document.getElementById('name').value.trim();
    const email = document.getElementById('email').value.trim();
    const message = document.getElementById('message').value.trim();

    let ok = true;
    errName.textContent = '';
    errEmail.textContent = '';
    errMessage.textContent = '';
    result.textContent = '';

    if (name.length < 2){ errName.textContent = 'Tên phải có ít nhất 2 ký tự.'; ok = false; }
    if (!isEmail(email)){ errEmail.textContent = 'Email không hợp lệ.'; ok = false; }
    if (message.length < 10){ errMessage.textContent = 'Nội dung tối thiểu 10 ký tự.'; ok = false; }

    if (ok){
      result.textContent = 'Gửi thành công! Chúng tôi sẽ phản hồi sớm.';
      contactForm.reset();
    }
  });

  // ===== Auth (login/register) =====
  function getUsers(){ try { return JSON.parse(localStorage.getItem('users')||'[]'); } catch { return []; } }
  function setUsers(list){ localStorage.setItem('users', JSON.stringify(list)); }
  function getSession(){ try { return JSON.parse(localStorage.getItem('session')||'null'); } catch { return null; } }
  function setSession(session){ if (session) localStorage.setItem('session', JSON.stringify(session)); else localStorage.removeItem('session'); }

  function updateAuthUI(){
    const session = getSession();
    if (session){
      if (userBadge){ userBadge.style.display = 'inline-block'; userBadge.textContent = session.name || session.email; }
      if (authOpen){ authOpen.textContent = 'Đăng xuất'; }
    } else {
      if (userBadge){ userBadge.style.display = 'none'; userBadge.textContent = ''; }
      if (authOpen){ authOpen.textContent = 'Đăng nhập'; }
    }
  }

  function openModal(){ authModal?.classList.add('show'); }
  function closeModal(){ authModal?.classList.remove('show'); }

  authOpen?.addEventListener('click', () => {
    const session = getSession();
    if (session){
      setSession(null); // logout
      updateAuthUI();
    } else {
      openModal();
    }
  });
  authModal?.querySelectorAll('[data-close]')?.forEach(btn => btn.addEventListener('click', closeModal));

  // Switch tabs in auth modal (reuse tab logic already in page)
  authModal?.querySelectorAll('.tab')?.forEach(tab => {
    tab.addEventListener('click', () => {
      const id = tab.getAttribute('data-tab');
      authModal.querySelectorAll('.tab').forEach(t => t.classList.remove('active'));
      authModal.querySelectorAll('.tab-panel').forEach(p => p.classList.remove('active'));
      tab.classList.add('active');
      authModal.querySelector('#'+id)?.classList.add('active');
    });
  });

  // Register
  const registerForm = document.getElementById('registerForm');
  registerForm?.addEventListener('submit', e => {
    e.preventDefault();
    const name = document.getElementById('regName').value.trim();
    const email = document.getElementById('regEmail').value.trim().toLowerCase();
    const password = document.getElementById('regPassword').value;
    const errN = document.getElementById('err-reg-name');
    const errE = document.getElementById('err-reg-email');
    const errP = document.getElementById('err-reg-password');
    const res = document.getElementById('regResult');
    errN.textContent = errE.textContent = errP.textContent = res.textContent = '';
    let ok = true;
    if (name.length < 2){ errN.textContent = 'Tên tối thiểu 2 ký tự.'; ok = false; }
    if (!/^[\w-.]+@([\w-]+\.)+[\w-]{2,}$/i.test(email)){ errE.textContent = 'Email không hợp lệ.'; ok = false; }
    if (password.length < 6){ errP.textContent = 'Mật khẩu tối thiểu 6 ký tự.'; ok = false; }
    const users = getUsers();
    if (users.some(u => u.email === email)){ errE.textContent = 'Email đã tồn tại.'; ok = false; }
    if (!ok) return;
    users.push({ name, email, password });
    setUsers(users);
    // Tự động đăng nhập và chuyển về Trang chủ
    setSession({ email, name });
    updateAuthUI();
    closeModal();
    document.getElementById('home')?.scrollIntoView({ behavior: 'smooth', block: 'start' });
  });

  // Login
  const loginForm = document.getElementById('loginForm');
  loginForm?.addEventListener('submit', e => {
    e.preventDefault();
    const email = document.getElementById('loginEmail').value.trim().toLowerCase();
    const password = document.getElementById('loginPassword').value;
    const errE = document.getElementById('err-login-email');
    const errP = document.getElementById('err-login-password');
    const res = document.getElementById('loginResult');
    errE.textContent = errP.textContent = res.textContent = '';
    let ok = true;
    if (!/^[\w-.]+@([\w-]+\.)+[\w-]{2,}$/i.test(email)){ errE.textContent = 'Email không hợp lệ.'; ok = false; }
    if (password.length < 6){ errP.textContent = 'Mật khẩu không đúng định dạng.'; ok = false; }
    if (!ok) return;
    const users = getUsers();
    const user = users.find(u => u.email === email && u.password === password);
    if (!user){ res.textContent = 'Sai email hoặc mật khẩu.'; return; }
    setSession({ email: user.email, name: user.name });
    updateAuthUI();
    closeModal();
    document.getElementById('home')?.scrollIntoView({ behavior: 'smooth', block: 'start' });
  });

  updateAuthUI();
  // Lần đầu vào trang nếu chưa đăng nhập thì mở modal
  (function(){
    try {
      const s = JSON.parse(localStorage.getItem('session')||'null');
      if (!s) openModal();
    } catch { openModal(); }
  })();
})();

// ================= Cafe Store Logic =================
(function(){
  const fmt = n => (n||0).toLocaleString('vi-VN') + '₫';
  const PRODUCTS = [
    {id:'cf1', name:'Cà phê đen', price:20000, img:'https://picsum.photos/seed/cf1/600/400'},
    {id:'cf2', name:'Cà phê sữa', price:25000, img:'https://picsum.photos/seed/cf2/600/400'},
    {id:'cf3', name:'Bạc xỉu', price:28000, img:'https://picsum.photos/seed/cf3/600/400'},
    {id:'cf4', name:'Espresso', price:30000, img:'https://picsum.photos/seed/cf4/600/400'},
    {id:'cf5', name:'Latte', price:35000, img:'https://picsum.photos/seed/cf5/600/400'},
    {id:'cf6', name:'Cappuccino', price:35000, img:'https://picsum.photos/seed/cf6/600/400'},
    {id:'cf7', name:'Matcha Latte', price:42000, img:'https://picsum.photos/seed/cf7/600/400'},
    {id:'cf8', name:'Trà đào cam sả', price:32000, img:'https://picsum.photos/seed/cf8/600/400'},
  ];

  const productGrid = document.getElementById('productGrid');
  const cartList = document.getElementById('cartList');
  const subTotalEl = document.getElementById('subTotal');
  const taxEl = document.getElementById('tax');
  const grandTotalEl = document.getElementById('grandTotal');
  const checkoutBtn = document.getElementById('checkoutBtn');
  const orderForm = document.getElementById('orderForm');

  function loadCart(){ try {return JSON.parse(localStorage.getItem('cart')||'{}')} catch {return {}} }
  function saveCart(c){ localStorage.setItem('cart', JSON.stringify(c)); }

  function renderProducts(){
    if (!productGrid) return;
    productGrid.innerHTML = '';
    PRODUCTS.forEach(p => {
      const card = document.createElement('article');
      card.className = 'product';
      const imgSrc = p.img || `https://picsum.photos/seed/${p.id}/600/400`;
      card.innerHTML = `
        <div class="thumb-wrap">
          <img class="thumb" src="${imgSrc}" alt="${p.name}" loading="lazy" onerror="this.onerror=null;this.src='https://picsum.photos/seed/${p.id}-fallback/600/400'" />
        </div>
        <div class="meta">
          <span class="pill">#${p.id}</span>
          <h4>${p.name}</h4>
        </div>
        <div class="price">${fmt(p.price)}</div>
        <div class="actions">
          <button class="btn" data-add="${p.id}">Thêm</button>
        </div>`;
      productGrid.appendChild(card);
    });
    productGrid.querySelectorAll('[data-add]').forEach(btn => btn.addEventListener('click', () => addToCart(btn.getAttribute('data-add'))));
  }

  function calcTotals(cart){
    const items = Object.entries(cart);
    let sub = 0;
    for (const [id, qty] of items){
      const prod = PRODUCTS.find(p => p.id === id);
      if (prod) sub += prod.price * qty;
    }
    const tax = Math.round(sub * 0.08);
    const grand = sub + tax;
    return {sub, tax, grand};
  }

  function renderCart(){
    if (!cartList) return;
    const cart = loadCart();
    cartList.innerHTML = '';
    Object.entries(cart).forEach(([id, qty]) => {
      const prod = PRODUCTS.find(p => p.id === id);
      if (!prod) return;
      const li = document.createElement('li');
      li.className = 'cart-item';
      li.innerHTML = `
        <span>${prod.name}</span>
        <span class="pill">${fmt(prod.price)}</span>
        <div class="qty">
          <button class="btn" data-dec="${id}">-</button>
          <span>${qty}</span>
          <button class="btn" data-inc="${id}">+</button>
        </div>
        <button class="btn" data-del="${id}">Xóa</button>
      `;
      cartList.appendChild(li);
    });

    cartList.querySelectorAll('[data-inc]').forEach(b => b.addEventListener('click', () => changeQty(b.getAttribute('data-inc'), 1)));
    cartList.querySelectorAll('[data-dec]').forEach(b => b.addEventListener('click', () => changeQty(b.getAttribute('data-dec'), -1)));
    cartList.querySelectorAll('[data-del]').forEach(b => b.addEventListener('click', () => removeItem(b.getAttribute('data-del'))));

    const {sub, tax, grand} = calcTotals(cart);
    if (subTotalEl) subTotalEl.textContent = fmt(sub);
    if (taxEl) taxEl.textContent = fmt(tax);
    if (grandTotalEl) grandTotalEl.textContent = fmt(grand);
  }

  function addToCart(id){
    const cart = loadCart();
    cart[id] = (cart[id]||0) + 1;
    saveCart(cart);
    renderCart();
  }
  function changeQty(id, d){
    const cart = loadCart();
    const q = (cart[id]||0) + d;
    if (q <= 0) delete cart[id]; else cart[id] = q;
    saveCart(cart);
    renderCart();
  }
  function removeItem(id){
    const cart = loadCart();
    delete cart[id];
    saveCart(cart);
    renderCart();
  }

  checkoutBtn?.addEventListener('click', () => {
    const session = (function(){ try { return JSON.parse(localStorage.getItem('session')||'null'); } catch { return null; } })();
    if (!session){
      alert('Vui lòng đăng nhập trước khi đặt hàng.');
      document.getElementById('authOpen')?.click();
      return;
    }
    orderForm.style.display = 'block';
    orderForm.scrollIntoView({behavior:'smooth'});
  });

  orderForm?.addEventListener('submit', e => {
    e.preventDefault();
    const name = document.getElementById('customer').value.trim();
    const phone = document.getElementById('phone').value.trim();
    const address = document.getElementById('address').value.trim();
    const errC = document.getElementById('err-customer');
    const errP = document.getElementById('err-phone');
    const errA = document.getElementById('err-address');
    const res = document.getElementById('orderResult');

    errC.textContent = errP.textContent = errA.textContent = res.textContent = '';

    let ok = true;
    if (name.length < 2){ errC.textContent = 'Tên tối thiểu 2 ký tự.'; ok = false; }
    if (!/^0\d{9,10}$/.test(phone)){ errP.textContent = 'Số điện thoại không hợp lệ.'; ok = false; }
    if (address.length < 5){ errA.textContent = 'Địa chỉ quá ngắn.'; ok = false; }

    if (!ok) return;

    const cart = loadCart();
    const {sub, tax, grand} = calcTotals(cart);
    const order = { id: 'ORD' + Date.now(), name, phone, address, cart, sub, tax, grand, createdAt: new Date().toISOString() };
    const orders = JSON.parse(localStorage.getItem('orders') || '[]');
    orders.push(order);
    localStorage.setItem('orders', JSON.stringify(orders));
    localStorage.removeItem('cart');

    renderCart();
    res.textContent = `Đặt hàng thành công! Mã đơn: ${order.id}. Tổng: ${fmt(grand)}`;
    orderForm.reset();
  });

  // init
  renderProducts();
  renderCart();
})();


