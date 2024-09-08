import * as THREE from 'three'

// Canvas

const canvas = document.querySelector('.webgl')


// Sizes

const sizes = {
    width : 800,
    height : 600
}

// Scene

const scene = new THREE.Scene()

/**
 * Axis Helper
 */

const axesHelper = new THREE.AxesHelper(2)
axesHelper.scale.set(4,4,4)
scene.add(axesHelper)

// Cube

const geometry = new THREE.BoxGeometry(1,1,1)
const material = new THREE.MeshBasicMaterial({color: 0xff0000})

const mesh = new THREE.Mesh(geometry,material)
mesh.scale.set(2,2,2)
scene.add(mesh)

// Camera 

const camera = new THREE.PerspectiveCamera(75,sizes.width/sizes.height)
camera.position.set(1.5,2,5)
scene.add(camera)


// Renderer
const renderer = new THREE.WebGLRenderer({canvas:canvas})
renderer.setSize(sizes.width,sizes.height)
renderer.render(scene,camera)
