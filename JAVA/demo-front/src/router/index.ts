import { createRouter, createWebHistory } from 'vue-router'
import Recommend from '../views/Recommend.vue'
import Login from '../views/Login.vue'
import Register from '../views/Register.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    { path: '/', name: 'home', component: Recommend },
    { path: '/login', name: 'login', component: Login },
    { path: '/register', name: 'register', component: Register },
  ],
})

export default router
