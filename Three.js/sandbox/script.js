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
const materials = [
    new THREE.MeshBasicMaterial({color: 0xff0000}), // Right side
    new THREE.MeshBasicMaterial({color: 0x00ff00}), // Left side
    new THREE.MeshBasicMaterial({color: 0x0000ff}), // Top side
    new THREE.MeshBasicMaterial({color: 0xffff00}), // Bottom side
    new THREE.MeshBasicMaterial({color: 0xff00ff}), // Front side
    new THREE.MeshBasicMaterial({color: 0x00ffff})  // Back side
]

const mesh = new THREE.Mesh(geometry, materials)
mesh.scale.set(1,1,1)
// mesh.rotation.x = Math.PI * 0.25
// mesh.rotation.y = Math.PI * 0.25
scene.add(mesh)

const group = new THREE.Group()
group.scale.y = 2
group.rotation.y = 0.2
scene.add(group)
  

// Camera 

const camera = new THREE.PerspectiveCamera(75,sizes.width/sizes.height)
camera.position.set(1.5,2,5)
camera.lookAt(new THREE.Vector3(0,-1,0))
scene.add(camera)


// Renderer
const renderer = new THREE.WebGLRenderer({canvas:canvas})
renderer.setSize(sizes.width,sizes.height)
renderer.render(scene,camera)
