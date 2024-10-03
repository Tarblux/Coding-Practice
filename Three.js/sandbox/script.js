import './style.css'
import * as THREE from 'three'
import gsap from 'gsap'
import { OrbitControls } from 'three/examples/jsm/Addons.js'


/**
 * Cursor
 */

const cursor = {
    x:0,
    y:0
}

window.addEventListener('mousemove',(event) => 
{
   cursor.x = event.clientX / sizes.width - 0.5
   cursor.y = -(event.clientY / sizes.height - 0.5)
//    console.log(cursor.x)

})

// Sizes

const sizes = {
    width : 800,
    height : 600
}

// Canvas

const canvas = document.querySelector('.webgl')

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


// Cube in a group
// const group = new THREE.Group()
// group.scale.y = 2
// group.rotation.y = 1
// scene.add(group)

// const cube1 = new THREE.Mesh(
//     new THREE.BoxGeometry(1, 1, 1),
//     new THREE.MeshBasicMaterial({ color: 0xff0000 })
// )
// cube1.position.x = 3
// group.add(cube1)

  

// Cameras

const camera = new THREE.PerspectiveCamera(75,sizes.width/sizes.height)
camera.position.set(1.5,2,5)
camera.lookAt(new THREE.Vector3(0,-1,0))
scene.add(camera)


// const aspectRatio = sizes.width / sizes.height
// const orthocamera = new THREE.OrthographicCamera(-1 * aspectRatio,1*aspectRatio,1,-1,0.1,100)
// orthocamera.position.set(1,1,2)
// orthocamera.lookAt(new THREE.Vector3(0,-1,0))
// scene.add(orthocamera)


// renderer

const renderer = new THREE.WebGLRenderer({canvas:canvas})
renderer.setSize(sizes.width,sizes.height)

// Controls

const controls = new OrbitControls(camera,canvas)


/**
 * Animate
 */

const clock = new THREE.Clock()

/**
 * GSAP
 */

// gsap.to(mesh.position,{duration:1, delay: 1, x : 2})

const tick = () =>{

    // Time
    const elapsedTime = clock.getElapsedTime()

    // Animated Rotation

    // mesh.rotation.y += 0.01
    // mesh.rotation.x += 0.01
    // mesh.rotation.x = Math.cos(elapsedTime)

    // Animated Renderer
    renderer.render(scene,camera)

    // // Linking camera to mouse movements
    // camera.position.x = Math.sin(cursor.x * Math.PI * 2) * 2
    // camera.position.z = Math.cos(cursor.x * Math.PI * 2) * 2
    // camera.position.y = cursor.y * 3
    // camera.lookAt(mesh.position)

    window.requestAnimationFrame(tick)
}

tick()