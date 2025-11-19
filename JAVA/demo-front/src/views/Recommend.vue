<!-- eslint-disable vue/multi-word-component-names -->
<script setup lang="ts">
import { onMounted, ref } from 'vue'
import { fetchEmbeddingRec, fetchHot, type Item } from '../api/recommend'

const LIMIT = 8
const userId = ref<number>(1)
const hotList = ref<Item[]>([])
const recList = ref<Item[]>([])
const loading = ref(false)

const normalizeTags = (item: Item) => item.tagsJson ?? '-'

const loadData = async () => {
  loading.value = true
  try {
    const [hotRes, recRes] = await Promise.all([fetchHot(LIMIT), fetchEmbeddingRec(userId.value, LIMIT)])
    hotList.value = Array.isArray(hotRes.data) ? hotRes.data.slice(0, LIMIT) : []
    recList.value = Array.isArray(recRes.data) ? recRes.data.slice(0, LIMIT) : []
  } catch (err) {
    hotList.value = []
    recList.value = []
    console.error('加载数据失败:', err)
  } finally {
    loading.value = false
  }
}

onMounted(loadData)
</script>

<template>
  <section class="hero">
    <div>
      <p class="eyebrow">向量驱动 · 个性推荐</p>
      <h1>为你量身定制的内容灵感</h1>
      <p class="description">
        根据用户行为Embedding召回相似项目，结合实时热榜，帮助你快速发现值得关注的内容。
      </p>
    </div>
    <button class="refresh" :disabled="loading" @click="loadData">
      {{ loading ? '刷新中...' : '刷新推荐' }}
    </button>
  </section>

  <section class="block">
    <div class="section-header">
      <div>
        <p class="eyebrow">Personalized Picks</p>
        <h2>向量推荐</h2>
      </div>
    </div>
    <div class="grid">
      <article v-for="(item, idx) in recList" :key="item.id ?? idx" class="card">
        <div class="card-title">{{ item.title ?? item.path ?? `Item #${idx + 1}` }}</div>
        <div class="card-tags">{{ normalizeTags(item) }}</div>
      </article>
      <div v-if="!loading && recList.length === 0" class="empty">暂无推荐，试试刷新或登录后再来~</div>
      <template v-if="loading">
        <div v-for="n in LIMIT" :key="'rec-skeleton-' + n" class="skeleton"></div>
      </template>
    </div>
  </section>

  <section class="block">
    <div class="section-header">
      <div>
        <p class="eyebrow">Trending Now</p>
        <h2>热榜</h2>
      </div>
    </div>
    <div class="grid">
      <article v-for="(hot, idx) in hotList" :key="hot.id ?? idx" class="card">
        <div class="card-title">{{ hot.title ?? hot.path ?? `Item #${idx + 1}` }}</div>
        <div class="card-tags">{{ normalizeTags(hot) }}</div>
      </article>
      <div v-if="!loading && hotList.length === 0" class="empty">热榜为空</div>
      <template v-if="loading">
        <div v-for="n in LIMIT" :key="'hot-skeleton-' + n" class="skeleton"></div>
      </template>
    </div>
  </section>
</template>

<style scoped>
.hero {
  display: flex;
  justify-content: space-between;
  align-items: center;
  gap: 24px;
  padding: 32px;
  border-radius: 24px;
  background: linear-gradient(135deg, #2563eb, #9333ea);
  color: #fff;
  margin-bottom: 32px;
}
.hero h1 {
  margin: 8px 0;
  font-size: 28px;
}
.description {
  max-width: 520px;
  color: rgba(255, 255, 255, 0.85);
}
.refresh {
  border: none;
  border-radius: 12px;
  padding: 12px 30px;
  background: #fff;
  color: #2563eb;
  font-size: 15px;
  font-weight: 600;
  cursor: pointer;
}
.refresh:disabled {
  opacity: 0.7;
  cursor: not-allowed;
}
.eyebrow {
  letter-spacing: 0.04em;
  font-size: 12px;
  text-transform: uppercase;
  color: rgba(15, 23, 42, 0.5);
}
.hero .eyebrow {
  color: rgba(255, 255, 255, 0.8);
}
.block {
  margin-bottom: 32px;
  background: #fff;
  padding: 20px 24px 26px;
  border-radius: 20px;
  box-shadow: 0 12px 30px rgba(15, 23, 42, 0.05);
}
.section-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 16px;
}
.section-header h2 {
  margin: 4px 0 0;
}
.grid {
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(220px, 1fr));
  gap: 14px;
}
.card {
  border: 1px solid #e5e7eb;
  border-radius: 12px;
  padding: 14px;
  background: #fff;
  box-shadow: 0 4px 12px rgba(15, 23, 42, 0.04);
  transition: transform 0.2s ease, box-shadow 0.2s ease;
}
.card:hover {
  transform: translateY(-4px);
  box-shadow: 0 8px 20px rgba(15, 23, 42, 0.08);
}
.card-title {
  font-weight: 600;
  margin-bottom: 6px;
  overflow: hidden;
  white-space: nowrap;
  text-overflow: ellipsis;
}
.card-tags {
  font-size: 13px;
  color: #64748b;
  word-break: break-all;
}
.empty {
  grid-column: 1 / -1;
  color: #94a3b8;
  padding: 20px 0;
  text-align: center;
}
.skeleton {
  height: 68px;
  border-radius: 12px;
  background: linear-gradient(90deg, #f3f4f6 25%, #e5e7eb 37%, #f3f4f6 63%);
  background-size: 400% 100%;
  animation: shimmer 1.4s ease infinite;
}
@keyframes shimmer {
  0% {
    background-position: 200% 0;
  }
  100% {
    background-position: -200% 0;
  }
}
</style>
