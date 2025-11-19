<!-- eslint-disable vue/multi-word-component-names -->
<script setup lang="ts">
import { ref } from 'vue'
import { useRouter } from 'vue-router'
import { register } from '../api/auth'

const router = useRouter()
const username = ref('')
const password = ref('')
const age = ref('')
const gender = ref('')
const selectedTags = ref<string[]>([])
const loading = ref(false)
const error = ref('')

const Tags = [
  'cooking',
  'cleaning',
  'shopping',
  'writing',
  'reading',
  'painting',
  'drawing',
  'running',
  'jogging',
  'cycling',
  'swimming',
  'skiing',
  'skateboarding',
  'surfing',
  'yoga',
  'weightlifting',
  'boxing',
  'karate',
  'taekwondo',
  'gymnastics',
  'singing',
  'dancing',
  'guitar',
  'beatboxing',
  'breakdancing',
  'graffiti',
]
const toggleTag = (tag: string) => {
  const index = selectedTags.value.indexOf(tag)
  if (index === -1) {
    selectedTags.value.push(tag)
  } else {
    selectedTags.value.splice(index, 1)
  }
}
const submit = async () => {
  error.value = ''
  if (!username.value || !password.value) {
    error.value = '请输入用户名和密码'
    return
  }

  const tagsString = selectedTags.value.join(',')

  const payload = {
    username: username.value,
    password: password.value,
    age: age.value ? Number(age.value) : undefined,
    gender: gender.value === '' ? undefined : gender.value === 'true',
    tagsJson: tagsString || undefined,
  }

  loading.value = true
  try {
    const res = await register(payload)
    const token = res.data?.token
    if (!token) {
      error.value = '注册失败: 未返回 token'
      return
    }
    localStorage.setItem('token', token)
    localStorage.setItem('username', username.value)
    window.dispatchEvent(new Event('auth-changed'))
    await router.push('/')
  } catch (err) {
    error.value =
      err instanceof Error ? err.message || '注册失败，请稍后重试' : '注册失败，请稍后重试'
    console.error(err)
  } finally {
    loading.value = false
  }
}
</script>

<template>
  <main class="form">
    <h2>注册</h2>
    <label>
      用户名
      <input v-model="username" type="text" placeholder="设置用户名" />
    </label>
    <label>
      密码
      <input v-model="password" type="password" placeholder="设置密码" />
    </label>
    <label>
      年龄（可选）
      <input v-model="age" type="number" min="0" placeholder="请输入年龄" />
    </label>
    <label>
      性别（可选）
      <select v-model="gender">
        <option value="">未选择</option>
        <option value="true">男</option>
        <option value="false">女</option>
      </select>
    </label>
    <div class="tags-field">
      <div class="tags-header">
        <span>兴趣标签（可多选）</span>
        <span class="hint">已选择 {{ selectedTags.length }}/{{ Tags.length }}</span>
      </div>
      <div class="tags-container">
        <button
          v-for="item in Tags"
          :key="item"
          type="button"
          class="tag"
          :class="{ active: selectedTags.includes(item) }"
          @click="toggleTag(item)"
        >
          {{ item }}
        </button>
      </div>
    </div>
    <button :disabled="loading" @click="submit">{{ loading ? '注册中...' : '注册' }}</button>
    <p v-if="error" class="error">{{ error }}</p>
    <p class="helper">
      已有账号？
      <RouterLink to="/login">去登录</RouterLink>
    </p>
  </main>
</template>

<style scoped>
.form {
  max-width: 420px;
  margin: 60px auto;
  padding: 32px 28px;
  border-radius: 16px;
  background: #fff;
  box-shadow: 0 18px 40px rgba(15, 23, 42, 0.08);
  display: flex;
  flex-direction: column;
  gap: 16px;
}
label {
  display: flex;
  flex-direction: column;
  gap: 6px;
  font-size: 14px;
  color: #1f2937;
}
input,
select {
  padding: 12px;
  border: 1px solid #e2e8f0;
  border-radius: 10px;
  font-size: 14px;
  transition: border 0.2s, box-shadow 0.2s;
}
input:focus,
select:focus {
  outline: none;
  border-color: #2563eb;
  box-shadow: 0 0 0 3px rgba(37, 99, 235, 0.15);
}
button {
  padding: 12px;
  background: linear-gradient(135deg, #16a34a, #22c55e);
  color: #fff;
  border: none;
  border-radius: 12px;
  cursor: pointer;
  font-size: 16px;
  font-weight: 600;
  transition: transform 0.2s ease, box-shadow 0.2s ease;
}
button:hover:not(:disabled) {
  transform: translateY(-1px);
  box-shadow: 0 10px 20px rgba(34, 197, 94, 0.3);
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
  text-align: center;
}
.tags-field {
  display: flex;
  flex-direction: column;
  gap: 10px;
  padding: 14px;
  border: 1px dashed #cbd5f5;
  border-radius: 12px;
  background: #f8fafc;
}
.tags-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  font-size: 14px;
  color: #1f2937;
}
.tags-header .hint {
  font-size: 12px;
  color: #94a3b8;
}
.tags-container {
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(110px, 1fr));
  gap: 10px;
}
.tag {
  padding: 8px 12px;
  border-radius: 999px;
  border: 1px solid #e2e8f0;
  background: #fff;
  font-size: 13px;
  color: #475569;
  cursor: pointer;
  transition: all 0.2s ease;
  text-transform: capitalize;
}
.tag:hover {
  border-color: #2563eb;
  color: #2563eb;
}
.tag.active {
  background: rgba(37, 99, 235, 0.12);
  color: #1d4ed8;
  border-color: transparent;
  box-shadow: inset 0 0 0 1px rgba(37, 99, 235, 0.3);
}
</style>
