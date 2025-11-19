import http from './http'

export interface Item {
  id: number
  title: string
  tagsJson: string
  path: string
  embeddingVector: string
}

export const fetchHot = (limit = 10) => http.get<Item[]>('/recommend/hot', { params: { limit } })

export const fetchEmbeddingRec = (userId: number, limit = 5) =>
  http.get<Item[]>('/recommend/embedding', { params: { userId, limit } })
