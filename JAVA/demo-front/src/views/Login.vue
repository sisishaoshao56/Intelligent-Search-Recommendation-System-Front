<!-- eslint-disable vue/multi-word-component-names -->
<script setup lang="ts">
import { ref } from 'vue'
import { useRouter } from 'vue-router'
import { login } from '../api/auth'

const router = useRouter()
const username = ref('')
const password = ref('')
const loading = ref(false)
const error = ref('')

const submit = async () => {
  error.value = ''
  if (!username.value || !password.value) {
    error.value = '请输入用户名和密码'
    return
  }
  loading.value = true
  try {
    const res = await login(username.value, password.value)
    const token = res.data?.token
    if (!token) {
      error.value = '登录失败: 未返回 token'
      return
    }
    localStorage.setItem('token', token)
    localStorage.setItem('username', username.value)
    window.dispatchEvent(new Event('auth-changed'))
    await router.push('/')
  } catch (err) {
    error.value = '登录失败，请检查账号密码'
    console.error(err)
  } finally {
    loading.value = false
  }
}
</script>

<template>
  <main class="form">
    <h2>登录</h2>
    <label>
      用户名
      <input v-model="username" type="text" placeholder="请输入用户名" />
    </label>
    <label>
      密码
      <input v-model="password" type="password" placeholder="请输入密码" />
    </label>
    <button :disabled="loading" @click="submit">{{ loading ? '登录中...' : '登录' }}</button>
    <p v-if="error" class="error">{{ error }}</p>
    <p class="helper">
      还没有账号？
      <RouterLink to="/register">去注册</RouterLink>
    </p>
  </main>
</template>

<style scoped>
.form {
  max-width: 360px;
  margin: 60px auto;
  padding: 24px;
  border: 1px solid #e5e7eb;
  border-radius: 8px;
  background: #fff;
  box-shadow: 0 2px 6px rgba(0, 0, 0, 0.05);
  display: flex;
  flex-direction: column;
  gap: 12px;
}
label {
  display: flex;
  flex-direction: column;
  gap: 6px;
  font-size: 14px;
}
input {
  padding: 10px;
  border: 1px solid #d1d5db;
  border-radius: 6px;
  font-size: 14px;
}
button {
  padding: 10px;
  background: #2563eb;
  color: #fff;
  border: none;
  border-radius: 6px;
  cursor: pointer;
}
button:disabled {
  opacity: 0.6;
  cursor: not-allowed;
}
.error {
  color: #dc2626;
  font-size: 13px;
}
.helper {
  font-size: 13px;
  color: #666;
}
</style>
