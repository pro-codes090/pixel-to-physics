# Pixel to Physics

A CPU-first graphics and computational mathematics project in C. It starts with writing pixels and builds toward software rendering, geometry, physics simulation, and optimization. SDL3 is used for the window and input; the graphics and simulation code runs on the CPU.

## Project structure

- `src/apps/` — small programs for each learning milestone
- `src/common/` — shared image, color, and math utilities
- `src/platform/` — SDL window and input code
- `src/geometry/` — vectors, matrices, cameras, and geometry tests
- `src/raster/` — pixel, line, circle, and triangle drawing
- `src/raytrace/`, `src/simulation/`, `src/optimize/` — later project work
- `assets/` — sample scenes and data
- `notes/` — equations, experiments, and progress
- `outputs/` — rendered images and simulation results

Each milestone builds on the previous one, with the goal of understanding how the math becomes working code.


## Weekly work

- `week-01-first-image/` — Write a solid-color PPM image.
- `week-02-pixel-buffer/` — Add a pixel buffer, gradients, and an SDL window.
- `week-03-lines/` — Draw lines with Bresenham’s algorithm.
- `week-04-drawing-primitives/` — Draw circles and compose a small scene.
- `week-05-vectors/` — Implement 2D vectors, lengths, and angles.
- `week-06-segments/` — Calculate point-to-segment distance.
- `week-07-transforms/` — Apply 2D matrix transformations.
- `week-08-triangle-fill/` — Fill triangles and polygons.
- `week-09-camera-frame/` — Implement 3D vectors and a wireframe camera view.
- `week-10-projection/` — Compare perspective and orthographic projection.
- `week-11-depth-buffer/` — Rasterize 3D triangles with depth testing.
- `week-12-software-rasterizer/` — Render a textured cube using the CPU.
- `week-13-ray-sphere/` — Trace camera rays and intersect spheres.
- `week-14-lighting/` — Add surface normals, diffuse light, and shadows.
- `week-15-reflections/` — Add multiple objects and mirror reflections.
- `week-16-sampling/` — Add antialiasing and compare render times.
- `week-17-geometry-predicates/` — Test geometric intersections and edge cases.
- `week-18-area-integration/` — Estimate areas and explore numerical integration.
- `week-19-particle-motion/` — Simulate particles with numerical time steps.
- `week-20-springs/` — Simulate springs, oscillation, and energy drift.
- `week-21-collisions/` — Detect and resolve 2D circle collisions.
- `week-22-derivatives/` — Approximate derivatives with finite differences.
- `week-23-gradient-descent/` — Minimize a function with gradient descent.
- `week-24-least-squares/` — Fit a line and visualize its loss function.
- `week-25-capstone/` — Build a small renderer, ray tracer, or physics lab.
- `week-26-review/` — Profile, document, and revisit the challenge problems.

Each folder includes the C source, a short explanation of the math, build/run instructions, and the images or data produced that week.