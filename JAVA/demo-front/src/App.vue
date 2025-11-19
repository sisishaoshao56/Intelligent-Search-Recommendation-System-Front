<script setup lang="ts">
import { computed, onMounted, onUnmounted, ref } from 'vue'
import { RouterLink, RouterView, useRouter } from 'vue-router'

const router = useRouter()
const token = ref(localStorage.getItem('token') || '')
const username = ref(localStorage.getItem('username') || '')

const isAuthed = computed(() => !!token.value)
const greeting = computed(() => (isAuthed.value ? `欢迎，${username.value || '朋友'}` : '欢迎，访客'))
const statusText = computed(() => (isAuthed.value ? '账号已登录' : '尚未登录'))

const syncAuth = () => {
  token.value = localStorage.getItem('token') || ''
  username.value = localStorage.getItem('username') || ''
}

const logout = () => {
  localStorage.removeItem('token')
  localStorage.removeItem('username')
  token.value = ''
  username.value = ''
  window.dispatchEvent(new Event('auth-changed'))
  router.push('/login')
}

onMounted(() => {
  syncAuth()
  window.addEventListener('auth-changed', syncAuth)
})

onUnmounted(() => {
  window.removeEventListener('auth-changed', syncAuth)
})
</script>

<template>
  <main class="page">
    <header class="topbar">
      <div class="brand">
        <span class="logo">AI</span>
        <div class="brand-text">
          <strong>推荐 Demo</strong>
          <small>向量召回体验站</small>
        </div>
      </div>

      <nav class="nav">
        <RouterLink to="/">推荐</RouterLink>
        <RouterLink v-if="!isAuthed" to="/login">登录</RouterLink>
        <RouterLink v-if="!isAuthed" to="/register" class="primary">注册</RouterLink>
      </nav>

      <div class="user-info">
        <div>
          <div class="user-label">{{ greeting }}</div>
          <div class="user-status">{{ statusText }}</div>
        </div>
        <button v-if="isAuthed" class="ghost" @click="logout">退出</button>
      </div>
    </header>

    <section class="content">
      <RouterView />
    </section>
  </main>
</template>

<style scoped>
:global(body) {
  margin: 0;
  background: #f5f6fb;
}
.page {
  max-width: 1200px;
  margin: 0 auto;
  padding: 32px 24px 48px;
  font-family: 'Segoe UI', 'PingFang SC', 'Microsoft Yahei', sans-serif;
}
.topbar {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 18px 24px;
  border-radius: 16px;
  background: #fff;
  box-shadow: 0 12px 30px rgba(15, 23, 42, 0.08);
  margin-bottom: 28px;
}
.brand {
  display: flex;
  align-items: center;
  gap: 12px;
}
.logo {
  width: 44px;
  height: 44px;
  border-radius: 12px;
  display: flex;
  align-items: center;
  justify-content: center;
  font-weight: 700;
  color: #fff;
  background: linear-gradient(135deg, #2563eb, #7c3aed);
}
.brand-text strong {
  font-size: 18px;
}
.brand-text small {
  display: block;
  font-size: 12px;
  color: #94a3b8;
}
.nav {
  display: flex;
  gap: 12px;
}
.nav a {
  padding: 8px 14px;
  border-radius: 999px;
  color: #1e293b;
  text-decoration: none;
  font-size: 14px;
  transition: background 0.2s, color 0.2s;
}
.nav a.router-link-active {
  color: #2563eb;
  background: rgba(37, 99, 235, 0.08);
}
.nav .primary {
  background: #2563eb;
  color: #fff !important;
}
.user-info {
  display: flex;
  align-items: center;
  gap: 12px;
  font-size: 14px;
  color: #1e293b;
}
.user-label {
  font-weight: 600;
}
.user-status {
  font-size: 12px;
  color: #94a3b8;
}
.ghost {
  border: 1px solid #cbd5f5;
  background: transparent;
  color: #2563eb;
  border-radius: 999px;
  padding: 6px 18px;
  cursor: pointer;
  transition: background 0.2s, color 0.2s;
}
.ghost:hover {
  background: rgba(37, 99, 235, 0.1);
}
.content {
  min-height: 70vh;
}
</style>
